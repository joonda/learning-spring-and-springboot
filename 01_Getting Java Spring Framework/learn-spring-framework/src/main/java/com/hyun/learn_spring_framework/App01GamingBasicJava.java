package com.hyun.learn_spring_framework;

import com.hyun.learn_spring_framework.game.GameRunner;
import com.hyun.learn_spring_framework.game.PacmanGame;

public class App01GamingBasicJava {
    public static void main(String[] args) {

        // var game = new MarioGame(); // Mario game 객체 생성
        // var game = new SuperContraGame();
        var game = new PacmanGame();
        var gameRunner = new GameRunner(game); // GameRunner 객체 생성
        // Game은 GameRunner 클래스의 의존성이다.
        gameRunner.run(); // 게임 실행
    }
}
