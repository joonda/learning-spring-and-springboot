package com.hyun.springboot.learn_jpa_and_hibernate.course;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.Id;

@Entity // name을 활용하여 다른 테이블과 매핑할 수 있다.
public class Course {

    @Id
    private long id;

    @Column(name="name") // 엔터티와 테이블에서 이름이 같기 때문에 name 속성은 필요가 없으나, 예시로 넣어둠
    private String name;

    @Column(name="author")
    private String author;

    // 기본 생성자 (findById에서 매핑하기 위한 기본 생성자)
    public Course () {}

    // 생성자
    public Course(long id, String name, String author) {
        this.id = id;
        this.name = name;
        this.author = author;
    }

    // Getter
    public long getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getAuthor() {
        return author;
    }

    // Setter (매핑을 위한 기본 세터, 자동으로 setter와 매핑해준다.)
    public void setId(long id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    // toString (logging)
    @Override
    public String toString() {
        return "Course{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", author='" + author + '\'' +
                '}';
    }
}
