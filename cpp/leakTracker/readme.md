allocation_tracker enables callers to detect possible memory leaks in a cross platform way.
Note that some macros are not c++ standardized but most modern compilers support them.
See AllocationTrackerExample for usage. The code including the allocation_tracker.h file must be compiled with c++11 compiler or compiler supporting 
min version of c++11. Also the macro TRACK_MEMORY needs to be defined to including memory tracking.
<b> How this works </b>
I have provided an object (which is a static object exposed via singeleton pattern). Lets call it 
allocation tracker. The tracker keeps a list of all alive objects at any given time. In order to be tracked
a class needs to include a macro in it's declaration. Behind the scene the macro adds an object to the class.
The object acts as a token to the lifetime of the objects of that class. It also holds information about the 
name of the class (the name of the class is taken at compile time. So this solution works even without RTTI)
At tear down when the tracker dies it checks whether there is any object alive. It asserts if it finds anything
in the list of alive objects

