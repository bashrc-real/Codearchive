# Dependency injection vs Factory Pattern #
------
(Out of patience? Go to [TLDR][5] directly)

Both dependency injection and factory pattern are manifestation of [Inversion of Control] [1]. Both patterns deal with delegating the responsibility of creation of objects. 
## Factory pattern ##
In factory pattern the object requiring a dependency creates it by using a black box entity (Factory). The factory is usually part of a different module than those invoking the factory

```cpp
Car(){
    m_axle = ::BuildAxle();
    m_tyres = ::BuildTyreSet();
    .......................
}
```
## Dependency injection ##
In dependency injection the entity is passed the dependencies via either setters or through the constructor. So the creation of objects is not controlled by the requesting entity, but rather passed in form of interfaces.
```cpp
Car(IAxle axle, ITyreSet tyreSet) :  m_axle(axle), m_tyres(tyreSet) {}
```

## Comparison ##
While both techniques aim at decoupling entities, factory pattern tend to be slightly harder to test than dependency injection. Reason being that the nature and point of object creation is black box to the creator. Lets take a look at the above example of the car class. Lets say we have to simulate the case of a burst tyre and test the behavior of the car. With the dependency injection it would be as simple as:

```cpp
class FaultyTyre : Tyre 
{
FaultyTyre(Flag state) : m_state(state) {}
// members
};

auto car = new Car(new FaultyTyre(Flag::Deflated));
```
However with factory pattern this becomes slightly harder. A factory would require a static method at some level(for keeping this article language agnostic, lets just assume that a static method is some routine that is not bound to a particular object). Static entities have visibility in the entire module for most languages. To test our car with a faulty tyre we will require a mock factory. To create a mock of the the factory, the factory needs to be part of a seperate module than the requesting entity.
Now this is something that may vary a lot with the programming language/framework. A typical c++ project would use a different library for the factory which will be replaced by a mock library when linking with the unit tests. Python projects will most probably use [monkey patching][2]. c# and other windows framework will use some sort of patching (which usually relies on [registry hacks][3]). Although its a subjective matter, but I usually prefer to steer clear of anything that requires special programming language/framework features while designing.
For sake of completeness here is a sample on how to test an object with a factory pattern.

```cpp
class FaultyTyre : Tyre {}
// Test binary should not have visibility of the original BuildTyreSet method
static ITyreSet BuildTyreSet(){
   return new FaultyTyre();
}

auto car = new Car(); // responsibility on the car to call the mock factory
```
### So factory pattern may make testing slightly harder. What else? ###
Other problems with factory pattern over DI pattern may be:

1. Object creation is completely black box to the creator of the entity that invokes the factories. That makes it hard to figure out what does the object actually requires. 
2. Static analysis of dependencies is harder since the dependency is generated at runtime.


#### So factory pattern is useless? ####
There are hardly any paradigms in programming which could be shot down as useless. An example of that could be where a class would need to create a dependency only on certain code paths and the creation of the object is heavy.

```cpp
void Car::ArmBatMobile(){
     m_guns = ::CreateAndInitializeGuns(); // Batman has a  no-gun rule. This is an exceptional scenario
}
```

### Ok. I used DI and now my constructor is a mess. ###
While the answer would mostly depend on what your class intends to do (if your class has too many dependencies, it already smells like it needs a refactoring), you may want to look up [facade service][4].  

### <a name="TLDR"></a>TLDR  
------
If your focus is to have a testable design, and you have to chose a model of creation of objects, consider dependency injection over factory pattern. Obviously if you have weighed all options on how static factories can be mocked effectively, then a factory is what you need. 

[1]:https://en.wikipedia.org/wiki/Inversion_of_control
[2]:http://stackoverflow.com/questions/5626193/what-is-a-monkey-patch
[3]:http://blogs.msdn.com/b/rflaming/archive/2008/11/30/microsoft-detours-i-wish-i-had-deeper-hooks-into-windows.aspx
[4]:http://blog.ploeh.dk/2010/02/02/RefactoringtoAggregateServices/
[5]:https://github.com/bashrc-real/Codearchive/blob/master/Design%20Internalizations/DependencyInjectionVsFactoryPattern.md#TLDR
