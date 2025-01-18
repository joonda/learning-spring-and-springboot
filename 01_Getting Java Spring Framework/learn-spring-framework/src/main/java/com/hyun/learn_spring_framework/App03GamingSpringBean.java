package com.hyun.learn_spring_framework;

import com.hyun.learn_spring_framework.game.GameRunner;
import com.hyun.learn_spring_framework.game.GamingConsole;
import com.hyun.learn_spring_framework.game.PacmanGame;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class App03GamingSpringBean {
    public static void main(String[] args) {

        var context = new AnnotationConfigApplicationContext(GamingConfiguration.class);

        context.getBean(GamingConsole.class).up();
        context.getBean(GameRunner.class).run();
    }
}
