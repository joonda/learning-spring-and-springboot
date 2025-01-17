package com.hyun.learn_spring_framework;

import com.hyun.learn_spring_framework.game.GameRunner;
import com.hyun.learn_spring_framework.game.MarioGame;
import com.hyun.learn_spring_framework.game.SuperContraGame;

public class AppGamingBasicJava {
    public static void main(String[] args) {

        // var marioGame = new MarioGame(); // Mario game 객체 생성
        var superContraGame = new SuperContraGame();
        var gameRunner = new GameRunner(superContraGame); // GameRunner 객체 생성
        gameRunner.run(); // 게임 실행
    }
}
