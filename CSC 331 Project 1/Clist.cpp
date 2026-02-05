#include "Clist.h"

/***************************************************************/
/* Programmer: Mamadou Wague                                   */        
/* Date: September 18, 2024                                    */        
/* Purpose: Implementation of Circular Linked List class       */
/* Input: none                                                 */
/* Output: print function prints all items in the list         */
/***************************************************************/

    template <class T>
    Clist <T> :: Clist()  { 
        length = 0;
        first = NULL;
    }

    template <class T>     
    Clist <T> :: ~Clist()   { 
        destroy();
    }

    template <class T>        
    Clist <T> :: Clist (const Clist<T> & other)  { 
        copy (other);
    }

    template <class T>        
    const Clist <T> & Clist<T> :: operator= (const Clist<T> & other)  { 
        if (this != &other)  { 
             destroy();
             copy (other);
         }
            return *this;
        }

    template <class T>        
    bool Clist <T> :: isEmpty()   { 
        
      return first == NULL;  
   }

    template <class T>
    void Clist <T> :: insertItem(T item) {
 
    node <T> *p = new node <T>;
    p->info = item;

    if (first == NULL) {  
        first = p;
        p->next = first;   
    
   } else if (item >= first->info) {  
        p->next = first->next;
        first->next = p;
        first = p;         
 
    } else if (item <= first->next->info) {  
        p->next = first->next;
        first->next = p;                    

    } else {  
        node <T> *q = first->next;  
        while (q->next != first && q->next->info < item) {
            q = q->next;
     }
        p->next = q->next;
        q->next = p;
    }

    length++;
  } 
 
 
    template <class T>      
    void Clist <T> :: deleteItem(T item) {

    if (first == NULL) {
        cout << "\nLIST IS EMPTY\n";
        return;
    }

    node <T> *p = first;  
    node <T> *r = NULL;   

    do {
        if (p->info == item) {  

           if (p->next == p) {
                delete p;
                first = NULL;
                length = 0;
                return;           
    
        } else if (item == first->info) {       

            node <T> *last = first;
            while (last->next != first) {
                last = last->next;
            }
               first = first->next;
               last->next = first;
               delete p;
               length--;
    
         } else {      
                r->next = p->next;
                delete p;
                length--;
            }

        node <T> *temp = first;

        do {
            if (temp->info > first->info) {
                first = temp;
            }
                temp = temp->next;
            }  while (temp != first); 

            return;  
    }

        r = p;
        p = p->next;

    } while (p != first);

    cout << "\nITEM NOT FOUND\n";
  }  
  
 
    template <class T>
    void Clist <T> :: destroy()  { 
   
    if (first == NULL) {   
        return;
    }

    node <T> *p = first;
    node <T> *temp;

  do {
       temp = p->next;   
       delete p;         
       p = temp;         
   }  while (p != first); 
   
    first = NULL;        
    length = 0;
  }

    template <class T>
    void Clist <T> :: copy (const Clist<T> & other)   { 

    length = other.length;
   
    if (other.first == NULL)    
       first = NULL;
    else 
    {
       first = new node<T>;
       first->info = other.first->info;

       node <T> *p = other.first->next;
       node <T> *r = first;

       while (p != other.first) 
       {
         r->next = new node<T>;
         r->next->info = p->info;
         p = p->next;
         r = r->next;
       }

       r->next = first;     
    }

  }

    template <class T>        
    int Clist <T> :: getLength()  { 

    return length;
  }

    template <class T>       
    bool Clist <T> :: searchItem (T item) {

   if (first == NULL) {
        cout << "\nLIST IS EMPTY\n" << endl;
        return false;
    }
    
    node <T> *p = first->next;   
    
   do {
       if (p->info == item) {   
          return true;         
       }
        
        p = p->next;      
        
    }   while (p != first->next);   
   
     return false;         
   
   }


    template <class T>
    void Clist <T> :: printList() {
   
    if (first == NULL) {                
        cout << "\nLIST IS EMPTY\n";
    } else {
        cout << "\nLIST IS: \n";
        
        node <T> *p = first->next;  

        do {
            cout << p->info << endl;  
            p = p->next;              

        } while (p != first->next);   
    }
  } 
 

 
 

 


   
 
 

   
 

