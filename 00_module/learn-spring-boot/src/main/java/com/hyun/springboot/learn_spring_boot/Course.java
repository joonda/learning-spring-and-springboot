package com.hyun.springboot.learn_spring_boot;

public class Course {
    private long id;
    private String name;
    private String author;

    public Course(long id, String name, String author) { // 생성자
        this.id = id;
        this.name = name;
        this.author = author;
    }

    public String getAuthor() { // Getter
        return author;
    }

    public String getName() { // Getter
        return name;
    }

    public long getId() { // Getter
        return id;
    }

    @Override
    public String toString() { // toString method
        return "Course{" + "id=" + id + ", name='" + name + '\'' + ", author='" + author + '\'' + '}';
    }
}
