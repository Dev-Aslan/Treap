#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int arr[];static int i=0;										// array to store the Treap, i is the length of the array
struct Treap													//Treap is The node with key, priority, and pointer to right,left child and parenter	
{	int key,priority;							
	struct Treap *right,*left,*parent;
	
};
struct Treap* newNode(int item)									// creating a New Node 
{	struct Treap *temp=(struct Treap *)malloc(sizeof(struct Treap));
	temp->key = item;											// set key value to value given by user
	temp->left=NULL;											//pointer to left and right  child is null
	temp->right=NULL;											
	temp->priority=	rand()%100;									//generating priority of every node randomlly
	return temp;
}
struct Treap *RightRotate(struct Treap *y )			
{	struct Treap *x=y->left,*T2= x->right;
	x->right=y;										// performing right Rotation on Y
	y->left= T2;
	return x;
}
struct Treap *LeftRotate(struct Treap *x)
{	struct Treap *y=x->right,*T2;
	T2=y->left;										// performing Left rotation on X

	y->left=x;
	x->right= T2;
	return y;
}
struct Treap* search(struct Treap* root , int key)
{	if (root == NULL|| root->key==key)
	{	return root;
	}
	if (root->key<key)
	{	return search(root->right,key);				
	}
	else if(root->key>key)
	{	return search(root->left,key);
	}
	else
	{ printf("\nNot Found\n");
	}
}
struct Treap* insert(struct Treap* Treap,int key)			// function to insert a new node
{		
	if(Treap==NULL)
	return newNode(key);
	
	if(key<Treap->key)
	{
	Treap->left= insert(Treap->left,key);
	if(Treap->left->priority>Treap->priority)
		Treap=RightRotate(Treap);
	}
	else if(key>Treap->key)
	{
	Treap->right= insert(Treap->right,key);
	if(Treap->right->priority>Treap->priority)
		Treap=LeftRotate(Treap);
		}
	
	return Treap;
	
}
int Height(struct Treap * root )
{	
		if (root==NULL)
			return 0;
		else
			{int Ldepth= Height(root->left);			// calculate height of all left sub tree
			 int Rdepth= Height(root->right);			// calculate height of all right Sub tree
				if(Ldepth>Rdepth)
				return(Ldepth+1);
				else
				return (Rdepth+1);
				}	
}
void Predecessor( int key)
{	int x=0,l=0;
	while(key!= arr[x] )								// searching in the array for predecessor
		{
		x++;l++;}
	if (i!=1&&l>=2)printf("\nPredecessor of %d is %d \n",arr[x],arr[x-1]);
	else
		printf("\n No predecessor");						
}
void Successor(int key)
{	int x=0,l=0;
	while(key!= arr[x] )								//searching in the array for the successor
		{
		x++;l++;}
		
	if (arr[x+1]!=0)printf("\nSuccessor of %d is %d \n",arr[x],arr[x+1]);
	else
		printf("\n No Successor");
}
void store(int val)								// storing treap as an array
{	arr[i]=val;
	i++;
	
}
void print(struct Treap * temp)
{	int i=0;
	if(temp==NULL)
	{return;
	}
	if(temp->left!= NULL)
		{	print(temp->left);
		}
		store(temp->key);			// storing every node key value as element of an array
		
		printf("%d ",temp->key);
		
	if (temp->right!=NULL)
		{print(temp->right);
			}	
}
struct Treap * deleteNode(struct Treap *root,int key)		// function to delete a node
{	if (root == NULL)
	return root;
	
	if(key<root->key)
	{root->left = deleteNode(root->left,key);}
	else if(key>root->key)
	{root ->right= deleteNode(root->right,key);
	}
	
	
    // IF KEY IS AT ROOT 
  
    // If left is NULL 
	else if (root->left ==NULL )
	{	struct Treap * temp= root->right;
		free(root);

		root= temp;	// Make right child as root 
	}
	// If Right is NULL 
	else if(root->right ==NULL)
	{	struct Treap *temp = root->left;
	free(root);

		root= temp;	// Make left child as root
	}
	// If key is at root and both left and right are not NULL 
	else if(root->left->priority>root->right->priority)
		{	root = RightRotate(root);
			root->right= deleteNode(root->right,key);
		}
	else
	{	root = LeftRotate(root);
		root->left= deleteNode(root->left,key);
	}
	return root;	
}

int main()
{	struct Treap *root=NULL,*temp;
	char x;
	
	
	int choice;
	int node_to_search,node_to_enter,node_to_delete,predecessor,successor;
do{

	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Search\n");
	printf("4.Print\n");
	printf("5.Find Predecessor\n");
	printf("6.Find Successor\n");
	printf("7.Height\n");
	printf("Enter Your Choice -: ");
	scanf("%d",&choice);
	
	switch(choice)
	{	case 1:printf("Enter the number to insert - : ");
			scanf("%d",&node_to_enter);
			root=insert(root,node_to_enter);
			printf("want to continue Y/N -:");
			getchar();
			scanf("%c",&x);
			break;
			
					
			
		case 2 :printf("Enter the number to delete - : ");				//Call delete function to delete a node
				scanf("%d",&node_to_delete);
				temp=deleteNode(root,node_to_delete)	;
																		
				break;
		case 3 :printf("Enter the number to search - : ");
				scanf("%d",&node_to_search);
				struct Treap *temp=search(root,node_to_search);
				(temp==NULL)?printf("\nKey Not Found\n"):printf("\nFound\n");				//Call seach function to search a node
				break;
		case 4:	printf("\nTreap-: ");
				print(root);
				printf("\n\n");											// call print function to print the treap		
				break;	
		case 5: printf("\nEnter the key of which you want to find Predecessor\n");
				scanf("%d",&predecessor);
				Predecessor(predecessor);								// call the function to find the Predecessor
				printf("\n")	;

				break;
		case 6: printf("\nEnter the key of which you want to find Succcessor\n");
				scanf("%d",&successor);
				Successor(successor);									// call the function to find the Successor
				break;			
		case 7:printf("Height Of the Tree=%d\n",Height(root));			// call the function to find the height of the tree	
		default: printf("\n");			
	}
	printf("\n");
}while(x=='Y'||x=='y');

	
	
}
