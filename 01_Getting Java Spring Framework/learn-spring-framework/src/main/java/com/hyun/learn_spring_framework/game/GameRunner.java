package com.hyun.learn_spring_framework.game;

public class GameRunner {
    private SuperContraGame game; // 의존성
    public GameRunner(SuperContraGame game) { // 생성자를 통한 의존성 주입
        this.game = game;
    }

    public void run() {
        System.out.println("Running game : " + game);
        game.up();
        game.down();
        game.left();
        game.right();
    }
}
