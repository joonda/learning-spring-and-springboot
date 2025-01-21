package com.hyun.learn_spring_framework.examples.d1;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Lazy;
import org.springframework.stereotype.Component;

import java.util.Arrays;

@Component
class ClassA {

}

@Component
@Lazy
class ClassB {
    private ClassA classA;
    public ClassB(ClassA classA) {
        System.out.println("Some Initialization logic");
        this.classA = classA;
    }

    public void doSomething() {
        System.out.println("Do Something");
    }
}

@Configuration
@ComponentScan // package 내에서 ComponentScan을 자동적으로 수행한다, 경로설정이 필요없다!
public class LazyInitializationLauncherApplication {

    private LazyInitializationLauncherApplication lazyInitializationLauncherApplication;

    public static void main(String[] args) {

        var context = new AnnotationConfigApplicationContext(LazyInitializationLauncherApplication.class);

        System.out.println("Initialization of context is completed"); // 지연 초기화 확인
        context.getBean(ClassB.class).doSomething(); // 지연 초기화 설정한 메서드 호출
    }
}
