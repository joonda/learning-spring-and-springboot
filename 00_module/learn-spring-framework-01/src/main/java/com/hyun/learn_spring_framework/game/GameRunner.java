package com.hyun.learn_spring_framework.game;

public class GameRunner {
    private GamingConsole game; // 외부에서 접근 불가 (변수 관리 차원)

    public GameRunner(GamingConsole game) { // 생성자를 통한 의존성 주입
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
