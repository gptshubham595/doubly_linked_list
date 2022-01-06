    /******************************************************************************
    
    Welcome to GDB Online.
    GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
    C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
    Code, Compile, Run and Debug online from anywhere in world.
    
    *******************************************************************************/
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #define BLOCKSIZE  10
    
    const int MAX = 10;
    int freeSpace=BLOCKSIZE;
    int extra=0;
    struct node {
       int data;
       struct node *next;
       struct node *prev;
    };
    
    //this link always point to first Link
    struct node *head = NULL;
    
    //this link always point to last Link 
    struct node *tail = NULL;
    
    struct node *evenCurr = NULL;
    struct node *oddCurr = NULL;
    int evenNo=0,oddNo=0;
    struct node *createNewNode(int data) {
       //create a link
       struct node *link = (struct node*) malloc(sizeof(struct node));
       link->data = data;
       link->next = NULL;
       link->prev = NULL;
       return link;
    }
    bool isEmpty() {
       return head == NULL;
    }
    struct node *curr =NULL;
    
    void freeNodes(int data) {
       struct node *link = createNewNode(data);
       //   h ⇌ l ⇌  t  
       curr->next=link;
       link->prev=curr;
       link->next=tail;
       tail->prev=link;
       curr=link;
    }
    void freeNodesAllocate(int data) {
       struct node *link = createNewNode(data);
       int i=evenNo;
       struct node *evenHead=tail;
       
       while(evenHead && i--)evenHead=evenHead->prev;
       //   h ⇌ l ⇌  t  
       curr->next=link;
       link->prev=curr;
       link->next=evenHead;
       evenHead->prev=link;
       curr=link;
    }
    int availableNodes(){
        
        return freeSpace=BLOCKSIZE-evenNo-oddNo+extra;
    }
    void printNodes(){
        
        printf("\n");
        struct node *curr = head;
        while(curr){
            printf("%d, ",curr->data);
            curr=curr->next;
        }
        printf("  :  COUNTER: %d\n",availableNodes());
    }
    void allocate(){
        if(availableNodes()>0)
            return;
        curr=head;
        int i=oddNo;
        while(curr && i--)curr=curr->next; //9
        struct node *temp=curr->next; //22
        for(int i=0;i<BLOCKSIZE;i++){
                freeNodesAllocate(-2);
            }
        curr->next=temp;
        extra=BLOCKSIZE;
        printf("\nALLOCATED NODES : ");
        printNodes();
    }
    void deallocate(){
        if(availableNodes()<=BLOCKSIZE)
            return;
        curr=head;
        int i=oddNo;
        while(curr && i--)curr=curr->next;
        struct node *temp=curr;
        for(int i=0;i<=BLOCKSIZE;i++){
                temp=temp->next;
            }
        curr->next=temp;
        extra=0;
        printf("\nDEALLOCATED NODES : ");
        printNodes();
    }
    void pull(int dir){
        if(availableNodes()>BLOCKSIZE){deallocate();}
        if(dir==0){
            //odd
            printf("\nPULLED ODD :");
            struct node *curr=head;
            int i=oddNo;
            while(curr && i--){
                curr=curr->next;
            }
            curr->data=-2;
            oddNo--;
        }
        else{
            //even
            printf("\nPULLED EVEN :");
            struct node *curr=tail;
            int i=evenNo;
            while(curr && i--){
                curr=curr->prev;
            }
            curr->data=-2;
            evenNo--;
        }
        printNodes();
    }
    void push(int data){
        if(availableNodes()<1){allocate();}
        printf("\nPUSHED %d :",data);
        
        bool isOdd=data&1;
        struct node *curr=head;
        if(isOdd){
            //odd
            oddNo++;
            int i=oddNo;
            while(curr && i--){
                curr=curr->next;
            }
            if(curr->data!=-2){
                //Full
                return;} 
            curr->data=data;
        }
        else{
            //even
            curr=tail;
            evenNo++;
            int i=evenNo;
            while(curr && i--){
                curr=curr->prev;
            }
            if(curr->data!=-2){
                //Full
                return;} 
            curr->data=data;
        }
        printNodes();
    }
    int getSignedInt(int *n){
        if(n==32)
            return 1;
        if(n==13)
            return 0;
    }
    void applyThis(char *line){
        printf("LINE= %s \n",line);
        char *buffer = ( char * ) malloc( strlen( line ) + 1 );
        buffer[0] = '\0';
        char *p = buffer;
        // if(line[0]!='-' && line[0]!='+')
        //     return;
        int runFunction=-1;
        if(line[0]=='+')
            runFunction=1;
        if(line[0]=='-')
            runFunction=0;
            
        for ( size_t i = 1; i < strlen( line ); i++ )
        {   
            if(line[i]>='0' && line[i]<='9'){
                *p++= line[i];*p = '\0';}
        }
        if(*buffer==' ' || *buffer=='\0')
            return;
        printf("%s : ",buffer);
        int i = atoi(buffer);
        
        i=i>MAX?i%MAX:i;
        printf("%d \n",i);
        if(i==0){
            printf("PULLING ALL\n");
            head->next=tail;
            tail->prev=head;
            printNodes();
            return;
        }
        if(runFunction==1){
            printf("PUSHING %d TIMES\n",i);
            for(int j=0;j<i;j++)
                push(-2);}
        if(runFunction==0){
            printf("PULLING %d TIMES\n",i);
            for(int j=0;j<i;j++)
                pull(-2);}
                
    }
    int main()
    {
        //STEP 1 
            // head=-1 , tail= -1 initialize
            head=createNewNode(-1);
            tail=createNewNode(-1);
            head->next=tail, tail->prev=head;
            
        //STEP 2
            curr=head;
            for(int i=0;i<BLOCKSIZE;i++){
                freeNodes(-2);
            }
            
        //STEP 3
            printNodes();
            push(0);
            push(1);
            push(2);
            push(3);
            push(4);
            push(5);
            push(6);
            push(7);
            push(8);
            push(9);

            pull(0); //odd
            pull(1); //even            
            
            push(22); //even            
            push(9);
            push(10);

            pull(1);
            pull(1);
            pull(1);
        //STEP 4
            char str1[2500];
            char newString[50][50]; 
            int i,j,ctr;
            printf(" Input  a string : ");
            fgets(str1, sizeof str1, stdin);	
            
            j=0; ctr=0;
            for(i=0;i<=(strlen(str1));i++)
            {
                if(str1[i]==' '||str1[i]=='\0')
                    newString[ctr][j]='\0',ctr++,j=0;    
                else
                    newString[ctr][j]=str1[i],j++;
            }
            
            printf("\n words after split by space are :\n");
            for(i=0;i < ctr;i++)
                applyThis(&newString[i]);
                
            
        return 0;
    }
