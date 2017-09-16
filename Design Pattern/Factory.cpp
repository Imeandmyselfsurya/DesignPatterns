/*
This code shows how to implement Factory Design Pattern.
Author: Suryasis Paul
Created: 16-09-2017
*/

#include<iostream> //includes the basic input output functionalities from iostream

/*
Interface to be inherited by all classes named Animals.
*/
class Animal
{
	public:
	virtual void Sound()=0; // declared virtual and void to allow inheritance and make it an abstract base class.
	
} ;
class Dog:public Animal //derives publicly from base class.
{
	void Sound()
	{
		std::cout<<"Bhow Bhow"<<std::endl; //overriding Sound() of base class Animal
	}
};

class Cat:public Animal //derives publicly from base class
{
	void Sound()
	{
		std::cout<<"Meow Meow"<<std::endl;//overriding Sound() of base class Animal
	}
};

class Factory
{
	private:
		Animal* typeOfAnimal;// a pointer of type Animal
	public:
		Animal* getInstance(int i)
		{
			
			if(i==1)
			{
	//			std::cout<<"I am here"<<std::endl;
				typeOfAnimal=new Dog();//calling the required constructor
			}
			if(i==2)
			{
				typeOfAnimal=new Cat();//calling the required constructor
			}
			
			return typeOfAnimal;//returns the required pointer
		}
};


int main()
{
	int myType; //the type required
	std::cin>>myType; //take as input the type
	Factory createAnimal;//creates a factory object
    Animal* myAnimal=createAnimal.getInstance(myType);//gets animal of the required type
  //  std::cout<<myAnimal<<std::endl;
//	std::cout<<"I am here"<<std::endl;
    if(myAnimal!=NULL)
    {
	
    myAnimal->Sound();//call Sound
   }
    else
    {
    	std::cout<<"Invalid Animal"<<std::endl;//if user enters something else
	}
	return 0;
}
