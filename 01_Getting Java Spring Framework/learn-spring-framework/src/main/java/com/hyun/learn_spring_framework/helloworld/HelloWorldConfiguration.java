package com.hyun.learn_spring_framework.helloworld;

import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Primary;

// Spring Container를 만들기 위한 Input
record Person (String name, int age, Address address) {}; // Add Address Class
record Address (String firstline, String city) {};

// Spring Container를 만들기 위한 Input2 (HelloWorldConfiguration)
@Configuration
public class HelloWorldConfiguration {

    @Bean
    public String name() {
        return "joonda";
    }

    @Bean
    public int age() {
        return 30;
    }

    // Add Address Class, using "new" and hard coding.
    @Bean
    public Person person() {
        return new Person("Ravi", 20, new Address("Gangseo", "Hwagok"));
    }

    // Call name, age methods plus address method
    @Bean
    public Person person2MethodCall() {
        return new Person(name(), age(), address());
    }

    @Bean
    public Person person3Parameters(String name, int age, Address address3) {
        // name, age, address3 (메서드 이름은 address지만, Bean이름은 address3이기때문)
        return new Person(name, age, address3);
    }

    @Bean
    @Primary
    public Person person4Parameters(String name, int age, Address address) {
        // name, age, address3 (메서드 이름은 address지만, Bean이름은 address3이기때문)
        return new Person(name, age, address);
    }

    @Bean
    public Person person5Qualifier(String name, int age, @Qualifier("address3Qualifier") Address address) {
        // name, age, address3 (메서드 이름은 address지만, Bean이름은 address3이기때문)
        return new Person(name, age, address);
    }

    @Bean
    public String firstline() {
        return "Gangseo";
    }

    @Bean
    public String city() {
        return "Hwagok";
    }

    @Bean (name = "address2") // Bean name Change
    @Primary // 중복되는 Bean에서 기본 값을 설정.
    public Address address() {
        return new Address("GangNamDaero", "NoneHyun");
    }

    @Bean (name = "address3") // Bean name Change
    @Qualifier("address3Qualifier")
    public Address address3() {
        return new Address("GangSeoDaero", "ShinJeong");
    }
}
