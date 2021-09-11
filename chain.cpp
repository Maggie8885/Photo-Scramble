#include "chain.h"
#include <cmath>
#include <iostream>


// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain() {
  	 clear();
      delete head_;
      head_ = NULL;
      length_ = 0;
      height_ = 0;
      width_ = 0;
  	
}

/**
 * Inserts a new node after the node pointed to by p in the
 * chain (so p->next is the new node) and returns a pointer to
 * the newly created node.
 * If p is NULL, inserts a new head node to the chain.
 * This function **SHOULD** create a new Node and increase length_.
 *
 * @param p = The new node should be pointed to by p->next.
 *            If p is NULL, the new node becomes the head of the chain.
 * @param ndata = The data to be inserted.
 */
Chain::Node * Chain::insertAfter(Node * p, const Block &ndata) {
	Node *newNode = new Node(ndata);
	if (p == NULL) {
		head_= newNode;
		newNode -> next = NULL;
		newNode -> prev = NULL;
		length_++;
		return newNode;
	} else if (p -> next == NULL) {
    p -> next = newNode;
    newNode->prev = p;
		newNode -> next = NULL;
		length_++;
		return newNode;
	} else {
		newNode -> next = p -> next;
		p -> next = newNode;
		newNode -> prev = p;
		newNode -> next -> prev = newNode;
		length_++;
		return newNode;
	}
  
}

/**
 * Swaps the position in the chain of the two nodes pointed to
 * by p and q.
 * If p or q is NULL or p==q, do nothing.
 * Change the chain's head pointer if necessary.
 */
void Chain::swap(Node *p, Node *q) {
  if (p == NULL || q == NULL || p == q ){
  	return;
  } 

  Node *p_prev = p -> prev;
  Node *p_next = p -> next;
  Node *q_prev = q -> prev;
  Node *q_next = q -> next;

// q is adjacient to p
  if (p_next== q ){
    //p is not head
  	if(p_prev!=NULL){
      //q is tail
      if(q_next==NULL){
        p_prev -> next = q;
        q -> next = p;
        p -> next = NULL;
        p -> prev = q;
        q -> prev = p_prev;
        return;
      } 
      //q is not tail
      else {
        q_next -> prev = p;
        q -> next = p;
        p -> next = q_next;
        p -> prev = q;
        q -> prev = p_prev;
        p_prev -> next = q;  
        return;   
      }
    } 
    // p is head
    else {
      // q is tail
      if(q_next == NULL){
        head_ = q;
        q -> prev = NULL;
        q -> next = p;
        p -> prev = q;
        p -> next = NULL;
        return;

      } 
      // q is not tail
      else {
        head_ = q;
        q -> prev = NULL;
        q -> next = p;
        p -> prev = q;
        p -> next = q_next;
        q_next -> prev = p; 
        return;
      }

    }
    
}


  if (q -> next == p) {
    if(q_prev!=NULL){
      if(p_next==NULL){
        q_prev -> next = p;
        p -> next = q;
        q -> next = p_next;
        q -> prev = p;
        p -> prev = q_prev;
        return;
      } else {
        p_next -> prev = q;
        p -> next = q;
        q -> next = p_next;
        q -> prev = p;
        p -> prev = q_prev;
        q_prev -> next = p;  
        return;   
      }
    } else {
      if(p_next == NULL){
        head_ = p;
        p -> prev = NULL;
        p -> next = q;
        q -> prev = p;
        q -> next = NULL;
        return;

      } else {
        head_ = p;
        p -> prev = NULL;
        p -> next = q;
        q -> prev = p;
        q -> next = p_next;
        p_next -> prev = q; 
        return;

      }

    }
  }


  if (p -> next != q && q -> next != p){
    if (p_prev != NULL) {
      if (q_next == NULL) {
        p -> next = NULL;
        p -> prev = q_prev;
        q_prev -> next = p;
        p_next -> prev = q;
        q -> next = p_next;
        q -> prev = p_prev;
        p_prev -> next = q;
        return;
      } else {
        p -> next = q_next;
        q_prev -> prev = p;
        p -> prev = q_prev;
        q_prev -> next = p;
        p_next -> prev = q;
        q -> next = p_next;
        q -> prev = p_prev;
        p_prev -> next = q;
        return;
      }
    } else {
      if (q_next == NULL) {
        head_ = q;
        q -> prev = NULL;
        q -> next = p_next;
        p_next -> prev = q;
        q_prev -> next = p;
        p -> prev = q_prev;
        p -> next = NULL; 
        return;
      } else {
        head_ = q;
        q -> prev = NULL;
        q -> next = p_next;
        p_next -> prev = q;
        q_prev -> next = p;
        p -> prev = q_prev;
        p -> next = q_next; 
        q_next -> prev = p;
        return;
      }

    }


    if (q_prev != NULL) {
      if (p_next == NULL) {
        q -> next = NULL;
        q -> prev = p_prev;
        p_prev -> next = q;
        q_next -> prev = p;
        p -> next = q_next;
        p -> prev = q_prev;
        q_prev -> next = p;
        return;
      } else {
        q -> next = p_next;
        p_next -> prev = q;
        q -> prev = p_prev;
        p_prev -> next = q;
        q_next -> prev = p;
        p -> next = q_next;
        p -> prev = q_prev;
        q_prev -> next = p;
        return;
      }
    } else {
      if (p_next == NULL) {
        head_ = p;
        p -> prev = NULL;
        p -> next = q_next;
        q_next -> prev = p;
        p_prev -> next = q;
        q -> prev = p_prev;
        q -> next = NULL; 
        return;
      } else {
        head_ = p;
        p -> prev = NULL;
        p -> next = q_next;
        q_next -> prev = p;
        p_prev -> next = q;
        q -> prev = p_prev;
        q -> next = p_next; 
        p_next -> prev = q;
        return;
      }

    }
  }
}

















/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear() {
if (head_->next == head_){
    return;
  }
  else{
    delete_node(head_->next);
    head_->next = head_;
    head_->prev = head_;
    length_ = 0;
  }  
}

// *
//  * Makes the current object into a copy of the parameter:
//  * All member variables should have the same value as
//  * those of other, but the memory should be completely
//  * independent. This function is used in both the copy
//  * constructor and the assignment operator for Chains.
 
void Chain::copy(Chain const &other) {
 height_ = other.height_;
  width_ = other.width_;
  Node* current_cursor = head_;
  Node* other_cursor = other.head_->next;
  while(other_cursor != other.head_){
    Node* new_node = new Node(other_cursor->data);
    current_cursor->next = new_node;
    new_node->prev = current_cursor;
    current_cursor = current_cursor->next;
    other_cursor = other_cursor->next;
  }
  current_cursor->next = head_;
  head_->prev = current_cursor;
  length_ = other.length_;
}
  

/* Modifies the current chain: 
 * 1) Find the node with the first (leftmost) block in the unscrambled
 *    image and move it to the head of the chain.
 *	This block is the one whose closest match (to the left) is the
 *	largest.  That is, the distance (using distanceTo) to this block 
 *	is big for all other blocks.
 *	For each block B, find the distanceTo B from every other block
 *	and take the minimum of these distances as B's "value".
 *	Choose the block B with the maximum value over all blocks and
 *	swap its node to the head of the chain.
 *
 * 2) Starting with the (just found) first block B, find the node with
 *    the block that is the closest match to follow B (to the right)
 *    among the remaining blocks, move (swap) it to follow B's node,
 *    then repeat to unscramble the chain/image.
 */
void Chain::unscramble() {
  /* your code here */
Node* alhead = head_;
Node* curr = head_;
Node* testNode = curr;
Node* leftMost = head_;

double resVal = 0.0;
for(int i = 0; i < length_; i++) {
  
  testNode = head_;
  double resTemp = 1.0;
   for(int j = 0; j < length_; j++){
    if (curr != testNode) {
      double min = (testNode -> data).distanceTo(curr -> data);
      // double min = (curr -> data).distanceTo(testNode -> data);

      if (min <= resTemp) {
        resTemp = min;
      }
    }
    testNode = testNode -> next;
   
   }
    if (resVal <= resTemp){
      resVal = resTemp;
      leftMost = curr;
      
    }
    curr = curr -> next;
}

swap(alhead,leftMost);

Node *p, *q, *k;
p = head_;
for (int i = 0; i<length_-1;i++){
  double res = 1.0;
  q = p -> next;
  for(int j = i; j<length_-1; j++){
    double mid = (p->data).distanceTo(q->data);
    if(mid <= res){
      res =mid;
      k = q;

    }
    q=q->next;

  }
  swap(p->next,k);
  p = k;
}


}  






