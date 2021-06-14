/*
Important Points:
1.Overloading new and delete operator gives developer 
control of heap allocation.And we can do the following things with 
the control:
    a.Garbage collection
    b.Exception handling routine.
    c.It can be customize that the compiler-provided versions don't offer.
      For example: we can initialize something to the whole memory what we get
      from new operator.
    d.It can be used to track how much memory is not in use and we can reuse 
      it instead of asking from.

    //AND there are so many possiblities we can think and discuss.
*/