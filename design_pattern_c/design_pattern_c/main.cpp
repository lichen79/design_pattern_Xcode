#include <iostream>
#include "Factory.h"
#include "Product.h"
#include "AbstractFactory.h"
#include "AbstractProductA.h"
#include "AbstractProductB.h"
#include "ConcreteFactory1.h"
#include "ConcreteFactory2.h"

#include "Factory1.h"
#include "ConcreteFactory.h"
#include "Product1.h"

#include "ConcreteBuilder.h"
#include "Director.h"
#include "Builder.h"
#include "Product.h"

#include "Singleton.h"

#include "Proxy.h"

#include "Subject.h"
#include "Obeserver.h"
#include "ConcreteObeserver.h"
#include "ConcreteSubject.h"

#include "ConcreteColleagueA.h"
#include "ConcreteMediator.h"
#include "ConcreteColleagueB.h"

#include "Adapter.h"
#include "Adaptee.h"
#include "Target.h"

#include "ConcreteImplementorA.h"
#include "ConcreteImplementorB.h"
#include "RefinedAbstraction.h"
#include "Abstraction.h"

#include "Facade.h"

#include "ConcreteFlyweight.h"
#include "FlyweightFactory.h"
#include "Flyweight.h"

#include "Context.h"
#include "ConcreteStateA.h"
#include "ConcreteStateB.h"

#include "Context_Strategy.h"
#include "ConcreteStrategyA.h"
#include "ConcreteStrategyB.h"
#include "Strategy.h"
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    
    //SimpleFactory
    cout << "--------------------SimpleFactory--------------------" << endl;
	Product * prod = Factory::createProduct("A");
		
	prod->Use();
	
    prod = Factory::createProduct("B");
    
    prod->Use();
    
	delete prod;
    
    
    //AbstractFactory
    cout << "--------------------AbstractFactory--------------------" << endl;
    
    AbstractFactory * fc = new ConcreteFactory1();
    AbstractProductA * pa =  fc->createProductA();
    AbstractProductB * pb = fc->createProductB();
    pa->use();
    pb->eat();
    
   AbstractFactory * fc2 = new ConcreteFactory2();
    AbstractProductA * pa2 =  fc2->createProductA();
    AbstractProductB * pb2 = fc2->createProductB();
    pa2->use();
    pb2->eat();
    
    delete fc;
    delete pa;
    delete pb;
    delete fc2;
    delete pa2;
    delete pb2;	
    
    //FactoryMethod
    cout << "--------------------FactoryMethod--------------------" << endl;
    Factory1 * fc1 = new ConcreteFactory();
    Product1 * prod1 = fc1->factoryMethod();
    prod1->use();
    
    delete fc1;
    delete prod1;
    
    //Builder
    cout << "--------------------Builder--------------------" << endl;
    ConcreteBuilder * builder = new ConcreteBuilder();
    Director  director;
    director.setBuilder(builder);
    Product2 * pd =  director.constuct();
    pd->show();
    
    delete builder;
    delete pd;
    
    //Singleton
    cout << "--------------------Singleton--------------------" << endl;
    Singleton * sg = Singleton::getInstance();
    sg->singletonOperation();
    //delete sg;
    
    
    //Proxy
    cout << "--------------------Proxy--------------------" << endl;
    Proxy proxy;
    proxy.request();
    
    //Obeserver
    cout << "--------------------Obeserver--------------------" << endl;
    Subject * subject = new ConcreteSubject();
    Obeserver * objA = new ConcreteObeserver("A");
    Obeserver * objB = new ConcreteObeserver("B");
    subject->attach(objA);
    subject->attach(objB);
    
    subject->setState(1);
    subject->notify();
    
    cout << "--------------------" << endl;
    subject->detach(objB);
    subject->setState(2);
    subject->notify();
    
    delete subject;
    delete objA;
    delete objB;
    
    //Mediator
    cout << "--------------------Mediator--------------------" << endl;
    ConcreteColleagueA * mpa = new ConcreteColleagueA();
    ConcreteColleagueB * mpb = new ConcreteColleagueB();
    ConcreteMediator * mpm = new ConcreteMediator();
    mpm->registered(1,mpa);
    mpm->registered(2,mpb);
    
    // sendmsg from a to b
    mpa->sendmsg(2,"hello,i am a");
    // sendmsg from b to a
    mpb->sendmsg(1,"hello,i am b");
    
    delete mpa,mpb,mpm;
    
    
    //Adapter
    cout << "--------------------Adapter--------------------" << endl;
    Adaptee * adaptee  = new Adaptee();
    Target * tar = new Adapter(adaptee);
    tar->request();
    
    //Bridge
    cout << "--------------------Bridge--------------------" << endl;
    //de-coupling abstraction et implementation
    
    Implementor * bpImp = new ConcreteImplementorA();
    Abstraction * bpa = new RefinedAbstraction(bpImp);
    bpa->operation();
    
    Abstraction * bpb = new RefinedAbstraction(new ConcreteImplementorB());
    bpb->operation();
    
    bpImp = new ConcreteImplementorA();
    bpb = new RefinedAbstraction(bpImp);
    bpb->operation();

    
    delete bpa;
    delete bpb;
    
    
    //Facade
    cout << "--------------------Facade--------------------" << endl;
    Facade fa;
    fa.wrapOpration();

    
    
    //Flyweight
    cout << "--------------------Flyweight--------------------" << endl;
    
    FlyweightFactory factory;
    Flyweight * fw = factory.getFlyweight("one");
    fw->operation();
    
    Flyweight * fw2 = factory.getFlyweight("two");
    fw2->operation();
    //aready exist in pool
    Flyweight * fw3 = factory.getFlyweight("one");
    fw3->operation();
    
    //State
    cout << "--------------------State--------------------" << endl;
    char a = '0';
    if('0' == a)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    
    Context * c = new Context();
    c->request();
    c->request();
    c->request();
    
    delete c;
    //Strategy
    cout << "--------------------Strategy--------------------" << endl;
    Strategy * s1 = new ConcreteStrategyA();
    Context_Strategy * cxt = new Context_Strategy();
    cxt->setStrategy(s1);
    cxt->algorithm();
    
    Strategy *s2 = new ConcreteStrategyB();
    cxt->setStrategy(s2);
    cxt->algorithm();
    
    delete s1;
    delete s2;
    
    int rac1 = 0x1;
    int rac2 = 0x2;
    int rac3 = 0x4;
    int rac4 = 0x8;
    int rac5 = 0x16;
    int i = 0xe;
    int j = 0x5;
    
    int r1 = i & rac1;
    int r2 = i & rac2;
    int r3 = i & rac3;
    int r4 = i & rac4;
    int r5 = i & rac5;

    
    cout <<"res:" << r1 << "/" << r2 << "/" << r3 << "/" << r4 << "/"<< r5<<endl;
    
	return 0;
}
