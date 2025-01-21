package com.hyun.learn_spring_framework.examples.e1;

import jakarta.annotation.PostConstruct;
import jakarta.annotation.PreDestroy;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.stereotype.Component;

import java.util.Arrays;

@Component
class SomeClass {
    private SomeDependency someDependency;

    public SomeClass(SomeDependency someDependency) { // 생성자 의존성 넣기
        this.someDependency = someDependency;
        System.out.println ("All dependencies are ready!");
    }

    @PostConstruct
    public void initialize() { // 추가 작업
        someDependency.getReady();
    }

    @PreDestroy
    public void cleanup() {
        System.out.println("Cleanup");
    }
}

@Component
class SomeDependency {

    public void getReady() {
        System.out.println("Some logic using someDependency");
    }
}

@Configuration
@ComponentScan // package 내에서 ComponentScan을 자동적으로 수행한다, 경로설정이 필요없다!
public class PrePostAnnotationsContextLauncherApplication {

    public static void main(String[] args) {

        var context = new AnnotationConfigApplicationContext(PrePostAnnotationsContextLauncherApplication.class);

        Arrays.stream(context.getBeanDefinitionNames())
                .forEach(System.out::println);

        context.close();
    }
}
