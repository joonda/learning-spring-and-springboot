package com.hyun.learn_spring_framework.examples.g1;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

import java.util.Arrays;

@Configuration
@ComponentScan // package 내에서 ComponentScan을 자동적으로 수행한다, 경로설정이 필요없다!
public class SimpleSpringContextLauncherApplication {

    public static void main(String[] args) {

        var context = new AnnotationConfigApplicationContext(SimpleSpringContextLauncherApplication.class);

        Arrays.stream(context.getBeanDefinitionNames())
                .forEach(System.out::println);
    }
}
