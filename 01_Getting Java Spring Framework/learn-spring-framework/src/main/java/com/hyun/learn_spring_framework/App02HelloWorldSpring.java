package com.hyun.learn_spring_framework;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class App02HelloWorldSpring {
    public static void main(String[] args) {

        // 1. 스프링 컨텍스트 실행
        var Context = new AnnotationConfigApplicationContext(HelloWorldConfiguration.class);

        // 2. 스프링 프레임워크가 관리할 수 있도록 설정한다
        // HelloWorldConfiguration  - @Configuration
        // method name -> @Bean

        // 3. 스프링이 관리하는 Bean을 검색하고 있다.
        System.out.println(Context.getBean("name"));
        System.out.println(Context.getBean("age"));
        System.out.println(Context.getBean("firstline"));
        System.out.println(Context.getBean("city"));
        System.out.println(Context.getBean("person"));
        System.out.println(Context.getBean("address"));

    }
}
