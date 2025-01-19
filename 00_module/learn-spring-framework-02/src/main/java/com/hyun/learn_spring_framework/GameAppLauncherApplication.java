package com.hyun.learn_spring_framework;

import com.hyun.learn_spring_framework.game.GameRunner;
import com.hyun.learn_spring_framework.game.GamingConsole;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

@Configuration
@ComponentScan("com.hyun.learn_spring_framework.game")
public class GameAppLauncherApplication {

    public static void main(String[] args) {

        var context = new AnnotationConfigApplicationContext(GameAppLauncherApplication.class);

        context.getBean(GamingConsole.class).up();
        context.getBean(GameRunner.class).run();
    }
}
