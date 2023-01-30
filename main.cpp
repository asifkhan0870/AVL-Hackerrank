/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */


node *create(int data){
    
    node *temp=(node*) malloc(sizeof(node));
    temp->val=data;
    temp->left=NULL;
    temp->right=NULL;
    temp->ht=0;
    
    return temp;
}



int height(node *root){
    
      
    if(root==NULL){
        return -1;
    }
    
    return max(height(root->left),height(root->right))+1;
}


node *rightRotation(node *root){
       
    node *n=root->left;
    node *temp=n->right;
    n->right=root;
    
    root->left=temp;
    root->ht=height(root);
    
    n->ht=height(n);
    
    return n;
}




node *leftRotation(node *root){
    
    node *n=root->right;
    node *temp=n->left;
    n->left=root;
    
    root->right=temp;
    root->ht=height(root);
    n->ht=height(n);
    
    return n;
}




node * insert(node * root,int val)
{
	if(root==NULL){
        
        // root=(node*)malloc(sizeof(node));
        
        root=create(val);
        
        
        root->val=val;
        
        root->ht=height(root);
        return root;
    }
    
    if(val>root->val){
        root->right=insert(root->right,val);
    }else if(val<root->val){
        root->left=insert(root->left,val);
    }
    
    // now balancing code start from here
    
    int bf=height(root->left)-height(root->right);
    
    
    if(bf>1){  // means there is disturbence in left subtree
        
        
        int child_bf=height(root->left->left)-height(root->left->right);
        
        if(child_bf>0){
            // left left rotation
            
            // rotate right side
            
            root=rightRotation(root);
        }
        else if(child_bf<0) {
            
            // left right roatation
            
            // first rotate in left direction
            root->left=leftRotation(root->left);
            
            // then rotate in right direction
            
            root=rightRotation(root);
            
            
            
        }
    }
    else if(bf<-1){  // menas there is unbalancing in right subtree
        
        int child_bf=height(root->right->left)-height(root->right->right);
        
        if(child_bf>0){
            
            // right left rotation
            
            root->right=rightRotation(root->right);
            
            // then rotate in left direction
            
            root=leftRotation(root);
        }
        else if(child_bf<0){
            
            // right right rotation
            
            root=leftRotation(root);
        }
    }
    
    else {  // means there is no distrubence after inserting this node
        root->ht=height(root);
    }
    
    return root;
    
    
  
}