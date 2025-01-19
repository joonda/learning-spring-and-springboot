package com.hyun.learn_spring_framework.helloworld;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class App02HelloWorldSpring {
    public static void main(String[] args) {

        // 1. 스프링 컨텍스트 실행
        var context = new AnnotationConfigApplicationContext(HelloWorldConfiguration.class);

        // 2. 스프링 프레임워크가 관리할 수 있도록 설정한다
        // HelloWorldConfiguration  - @Configuration
        // method name -> @Bean

        // 3. 스프링이 관리하는 Bean을 검색하고 있다.
        System.out.println(context.getBean("name"));
        System.out.println(context.getBean("age")); // Integer type
        System.out.println(context.getBean("firstline")); //String type
        System.out.println(context.getBean("city")); // String type
        System.out.println(context.getBean("person")); // person in Person Class type
        System.out.println(context.getBean("person2MethodCall")); // person in Person Class type
        System.out.println(context.getBean("person3Parameters")); // person in Person Class type
        System.out.println(context.getBean("address2")); // address in Address Class type (Available Change Bean name)
        System.out.println(context.getBean(Address.class)); // Call Address Class.
        System.out.println(context.getBean(Person.class));
        System.out.println(context.getBean("person5Qualifier"));

//        Arrays.stream(context.getBeanDefinitionNames())
//                .forEach(System.out::println);
    }
}
