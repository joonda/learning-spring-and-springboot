package com.hyun.springboot.myfirstwebapp.todo;

import jakarta.validation.Valid;
import org.springframework.stereotype.Service;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Predicate;

@Service
public class TodoService {

    // 정적인 List를 만들것이기 때문에 static 포함
    // 클래스 로딩 시점에 메모리에 단 한 번 생성되며, 모든 객체가 공유
    // 모든 객체에서 동일한 리스트 상태를 유지

    private static List<Todo> todos = new ArrayList<>();

    private static int todosCount = 0;

    // 초기화
    static {
        todos.add(new Todo(++todosCount, "Hyun", "Learn AWS",
                LocalDate.now().plusYears(1), false));
        todos.add(new Todo(++todosCount, "Hyun", "Learn Full Stack Development",
                LocalDate.now().plusMonths(1), false));
        todos.add(new Todo(++todosCount, "Hyun", "Reading a Books",
                LocalDate.now().plusMonths(2), false));
    }

    public List<Todo> findByUsername(String username) {
        return todos;
    }

    public void addTodo(String username, String description, LocalDate targetDate, boolean done) {
        Todo todo = new Todo(++todosCount, username, description, targetDate, done);
        todos.add(todo);
    }
    
    public void deleteById(int id) {
        todos.removeIf(todo -> todo.getId() == id);
    }

    public Todo findById(int id) {
        return todos.stream()
                .filter(todo -> todo.getId() == id)
                .findFirst()
                .get();
    }

    public void updateTodo(@Valid Todo todo) {
        deleteById(todo.getId());
        todos.add(todo);
    }
}
