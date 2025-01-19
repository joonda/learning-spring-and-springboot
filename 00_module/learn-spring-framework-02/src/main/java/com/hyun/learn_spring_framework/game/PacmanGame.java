package com.hyun.learn_spring_framework.game;

import org.springframework.stereotype.Component;

@Component
public class PacmanGame implements GamingConsole {
    public void up() {
        System.out.println("Up");
    }

    public void down() {
        System.out.println("Down");
    }

    public void left() {
        System.out.println("Turn Left");
    }

    public void right() {
        System.out.println("Turn Right");
    }
}
