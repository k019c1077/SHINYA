class Dog{
    String name;
    int age;
    public static void vow(Dog mine)
    {
        System.out.println(mine.name + "「ワン」");
    }
    public static Dog newDog(String name,int age)
    {
        Dog dog = new Dog();
        dog.name=name;
        dog.age = age;
        return dog;
    }
}
class Kadai4{
public static void main(String[] args) {
    Dog poti = Dog.newDog("ぽち",2);    
    Dog.vow(poti);
}
}