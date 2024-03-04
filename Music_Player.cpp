# include<bits/stdc++.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

// Creating class
class node{

    public:

    string data;
    node* next;
    node* prev;

    node(string d){
        this->data=d;
        next=NULL;
        prev=NULL;
    }
};

string song;
node* head;
node* current; 

//Writing insert song at end of playlist function.
void insert_song(){
    cout<<"Please enter the name of song:"<<endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    getline(cin,song);
    node* new_node= new node(song);
    if(head==NULL){
        new_node->next=new_node;
        new_node->prev=new_node;
        head=new_node;
        current=new_node;
        return;
    }

    node* last=head->prev;
    new_node->prev=last;
    last->next=new_node;
    new_node->next=head;
    head->prev=new_node;
}

//Writing delete song from playlist function.
void delete_song(){

    if(head==NULL){
        cout<<"Playlist is empty."<<endl;
        return;
    }

    cout<<"Enter the name of song to delete:";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin,song);
    cout<<endl;
    node* ptr=head;
    do{
        if(ptr->next==ptr && ptr->data.compare(song) ){
            cout<<"One file deleted. Playlist empty."<<endl;
            head=NULL;
            delete ptr;
            return;
        }
        else if(ptr->data.compare(song)==0){
            node* pre=ptr->prev;
            node* nex=ptr->next;
            pre->next=nex;
            nex->prev=pre;
            head=nex;
            delete ptr;
            cout<<"Somg deleted from the queue."<<endl;
            return;
        }
        ptr=ptr->next;
    }while(ptr!=head);
    cout<<"Song not found."<<endl;
}

//Writing show song from playlist function.
void show(){

    if(head==NULL){
        cout<<"Playlist is empty."<<endl;
        return;
    }

    node* ptr=head;
    cout<<"\n";
    int i=1;
    cout<<"Displaying Playlist:"<<endl;
    do{
        cout<<i<<". "<<ptr->data<<endl;
        i++;
        ptr=ptr->next;
    }while(ptr!=head);
}


//Writing next song in playlist function.

void next_song(){
    if(current==NULL){
        cout<<"No song in playlist."<<endl;
    }
    else{
        current=current->next;
        cout<<"Playing next song:"<<current->data<<endl;
    }
}

//Writing prev song in playlist function.

void prev_song(){
    if(current==NULL){
        cout<<"No song in playlist."<<endl;
    }
    else{
        current=current->prev;
        cout<<"Playing previous song:"<<current->data<<endl;
    }
}


//Writing first song in playlist function.

void first_song(){

    if(head==NULL){
        cout<<"No song in playlist"<<endl;
    }
    else{
        cout<<"Playing first song:"<<head->data<<endl;
    }
}

//Writing last song in playlist function.

void last_song(){

    if(head==NULL){
        cout<<"No song in playlist"<<endl;
    }
    else{
        cout<<"Playing last song:"<<head->prev->data<<endl;
    }
}

//Writing a specific song in playlist function.

void specific_song(){

    if(head==NULL){
        cout<<"No song in playlist."<<endl;
        return;
    }

    cout<<"Please write name of song:";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin,song);
    cout<<endl;

    node* ptr=head;
    do{
        if(ptr->data.compare(song)==0){
            cout<<"Song found."<<endl;
            cout<<"Playing music:"<<ptr->data<<endl;
            return;
        }
        ptr=ptr->next;
    }while(ptr!=head);

    cout<<"No song with given name found."<<endl;
}



int main(){

menu:
int choice;
cout<<"----Please choose from list of acctions given below."<<endl;
cout<<"1. Add song."<<endl;
cout<<"2. Remove song."<<endl;
cout<<"3. Show playlist."<<endl;
cout<<"4. Play next song."<<endl;
cout<<"5. Play previous song."<<endl;
cout<<"6. Play first song."<<endl;
cout<<"7. Play last song."<<endl;
cout<<"8. Play specific song."<<endl;
cout<<"9. Exit"<<endl;


cin>>choice;

switch(choice){

    case 1: insert_song();
        break;

    case 2: delete_song();
        break;

    case 3: show();
        break;

     case 4: next_song();
        break;

    case 5: prev_song();
        break;

    case 6: first_song();
        break;

    case 7: last_song();
        break;

    case 8: specific_song();
        break;

    case 9: exit(0);
        break;

}

goto menu;
return 0;
}