#include "Test.h"
#include <cassert>
#include "Domain/Dog.h"
#include "Repo/Database.h"
#include "Repo/DynamicVectorTemplate.h"
#include "Service/Service.h"

void Test::testDog() {
        Dog dog = Dog("breed","name","https://upload.wikimedia.org/wikipedia/commons/thumb/f/f4"
                                     "/Florida_Box_Turtle_Digon3_re-edited.jpg/1200px-Florida_Box_Turtle_Digon3_"
                                     "re-edited.jpg",10);
        assert(dog.getBreed()=="breed");
        assert(dog.getName()=="name");
        assert(dog.getLink_to_photo()=="https://upload.wikimedia.org/wikipedia/commons/thumb/f/f4/Florida_"
                                      "Box_Turtle_Digon3_re-edited.jpg/1200px-Florida_Box_Turtle_Digon3_re-edited.jpg");
        assert(dog.getAge()==10);
        assert(dog.getId()==1);
        std::string testname = "name1";
        dog.setName(testname);
        int i=23;
         std::string testbreed = "breed2";
         dog.setAge(i);
         dog.setBreed(testbreed);
         std::string testlink = "idk";
         dog.setLink_to_photo(testlink);
         assert(dog.getBreed()=="breed2");
         assert(dog.getName()=="name1");
         assert(dog.getLink_to_photo()=="idk");
         assert(dog.getAge()==23);
         Dog dog2 = dog;
         assert(dog2.getBreed()=="breed2");
         assert(dog2.getName()=="name1");
         assert(dog2.getLink_to_photo()=="idk");
         assert(dog2.getAge()==23);
         assert(dog == dog2);
         testname = "name3";
         dog2.setName(testname);
         assert(dog != dog2);
         assert(dog.toString() == "Dog with the breed breed2, the name name1, age of 23, (id=1) and internet link is idk\n");
}

void Test::testDynamicVector() {
    DynamicVector<Dog> arr = DynamicVector<Dog>();

    assert(arr.getSize() == 0);

    Dog d1 = Dog("Bulldog", "Piggy", "https://www.petfinder.com/barnyard/festus-41370249/ak/fairbanks/fairbanks-north-star-borough-animal-control-ak12/",5);
    arr.add(d1);
    assert(arr.getItem(0).getBreed() == "Bulldog");

    Dog d2 = Dog("Food", "Peanut",  "https://www.petfinder.com/dog/peanut-37342395/ak/fairbanks/homeward-bound-pet-rescue-and-referral-ak29/",5);
    arr.add(d2);
    assert(arr.getSize() == 2);
    assert(arr.getItem(0) != arr.getItem(1));

    assert(arr.remove(d1.getId()));
    assert(arr.getSize() == 1);

    DynamicVector<Dog> arr2 = DynamicVector<Dog>();
    arr2 = arr2 + d1;
    arr2 = arr2 + d2;
    assert(arr2.getItem(0) == d1);
    assert(arr2.getItem(1) == d2);
    assert(arr2.getSize() == 2);

    DynamicVector<Dog> arr3 = DynamicVector<Dog>();
    Dog d3 = Dog("d3", "d3","link3",10);
    arr3.add(d3);
    assert(arr3.getSize() == 1);
    assert(arr3.getItem(0) == d3);
}

void Test::testService() {
    Database<Dog> dat;
    Service serv(dat);
    assert(serv.addDog("name","breed",10,"idk")==true);
    assert(serv.removeDog(7) == true);
    serv.addDog("name","breed",10,"idk");
    assert(serv.updateDog(1,8,"name2")==true);
    assert(serv.updateDog(2,8,"breed2")==true);
    assert(serv.updateDog(4,8,"idk2")==true);
    assert(serv.updateDog(3,8,"12")==true);
    serv.database.resetIterator();
    assert(serv.getCurrentDog() == serv.database.getItem(0));

}

void Test::testDatabase() {
    Database<Dog> dat;
    Dog dog("breed","name","idk",10);
    dat.add(dog);
    assert(dog == dat.getItem(0));
    assert(dat.getSize()==1);
    bool ok = dat.remove(dog.getId());
    assert(dat.getSize()==0);
    dat.add(dog);
    dat.resetIterator();
    bool x = dat.next();
    assert(dog == dat.getCurrentDog());
    Dog dog2("breed","name","idk",10);
    dat.add(dog2);
    bool y = dat.next();
    assert(dog2 == dat.getCurrentDog());
}

void Test::testAll() {
    this->testDog();
    this->testDynamicVector();
    this->testDatabase();
    this->testService();

}
