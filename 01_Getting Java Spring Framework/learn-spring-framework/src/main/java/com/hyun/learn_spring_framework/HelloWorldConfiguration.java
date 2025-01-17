package com.hyun.learn_spring_framework;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

record Person (String name, int age) {};
record Address (String firstline, String city) {};
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

    @Bean
    public Person person() {
        return new Person("Ravi", 20);

    }

    @Bean
    public String firstline() {
        return "Gangseo";
    }

    @Bean
    public String city() {
        return "Hwagok";
    }

    @Bean
    public Address address() {
        return new Address("GangNamDaero", "NoneHyun");
    }
}
