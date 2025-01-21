package com.hyun.learn_spring_framework.examples.g1;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.stereotype.Component;

import java.util.Arrays;

@Component // @Named
class BusinessService {
    private DataService dataService;

    @Autowired // @Inject
    public void setDataService(DataService dataService) {
        System.out.println("Setter Injection");
        this.dataService = dataService;
    }

    public DataService getDataService() {
        return dataService;
    }
}

@Component // @Named
class DataService {

}

@Configuration
@ComponentScan // package 내에서 ComponentScan을 자동적으로 수행한다, 경로설정이 필요없다!
public class CdiContextLauncherApplication {

    public static void main(String[] args) {

        var context = new AnnotationConfigApplicationContext(CdiContextLauncherApplication.class);

        Arrays.stream(context.getBeanDefinitionNames())
                .forEach(System.out::println);

        System.out.println(context.getBean(BusinessService.class).getDataService());
    }
}
