bool addProductBaseOnExpiry(Inventory *i, Product p) {
    // To do code logic here.
    Inventory hold_stack;
    
    initInventory(&hold_stack);
    
    NodePtr new_Node = malloc(sizeof(NodeType)), transfer;
    
    new_Node->prod = p;
    
    if(i->currQty + p.prodQty > 100) {
        return false;
    }
    
    while(!isEmpty(*i) && dateDifference(i->top->prod.expiry, p.expiry) >= 0) {
        transfer = i->top;
        
        i->top = i->top->link;
        
        transfer->link = hold_stack.top;
        hold_stack.top = transfer;
    }
    
    new_Node->link = i->top;
    i->top = new_Node;
    
    i->currQty += p.prodQty;
    
    while(!isEmpty(hold_stack)) {
        transfer = hold_stack.top;
        
        hold_stack.top = hold_stack.top->link;
        
        transfer->link = i->top;
        i->top = transfer;
    }
    

    return true;
}