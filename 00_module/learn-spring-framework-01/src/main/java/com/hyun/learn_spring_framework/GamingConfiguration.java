package com.hyun.learn_spring_framework;

import com.hyun.learn_spring_framework.game.GameRunner;
import com.hyun.learn_spring_framework.game.GamingConsole;
import com.hyun.learn_spring_framework.game.PacmanGame;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class GamingConfiguration {

    @Bean
    public GamingConsole game() {
        var game = new PacmanGame();
        return game;
    }

    @Bean
    public GameRunner gameRunner(GamingConsole game) {
        var gameRunner = new GameRunner(game); // GameRunner 객체 생성
        return gameRunner;
    }
}
