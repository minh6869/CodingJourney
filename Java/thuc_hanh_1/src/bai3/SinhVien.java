/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package bai3;

import java.util.*;

/**
 *
 * @author Bugs
 */
public class SinhVien {
    private String ma_sinh_vien;
    private String ten;
    private int tuoi;
    private int nam_sinh;
    private double diem_trung_binh;
    
    public void nhap_ma_sinh_vien(){
        Scanner sv = new Scanner(System.in);
        System.out.println("Nhap ma sinh vien: ");
        String masv = sv.nextLine();
        this.ma_sinh_vien = masv;
        sv.close();
    }
    public void nhap_tensv(){
        Scanner sv = new Scanner(System.in);
        System.out.println("Nhap ten sinh vien: ");
        String name = sv.nextLine();
        this.ten = name;
        sv.close();
    }
    public void nhap_tuoisv(){
        Scanner sv = new Scanner(System.in);
        System.out.println("Nhap tuoi sinh vien: ");
        int age = sv.nextInt();
        this.tuoi = age;
        sv.close();
    }
    public void nhap_nam_sinhsv(){
        Scanner sv = new Scanner(System.in);
        System.out.println("Nhap ma sinh vien: ");
        int nam_sinh1 = sv.nextInt();
        this.nam_sinh = nam_sinh1;
        sv.close();
    }
    public void nhap_diem_trung_binh(){
        Scanner sv = new Scanner(System.in);
        System.out.println("Nhap diem trung binh sinh vien");
        double gpa = sv.nextDouble();
        this.diem_trung_binh = gpa;
        sv.close();
    }
    
    /**
     *
     */
    public void xuat_thong_tin(){
        System.out.println("thong tin sinh vien:" + this.ma_sinh_vien);
        System.out.println("ten sinh vien: " + this.ten);
        System.out.println("tuoi sinh vien: " + this.tuoi);
    }   
    
}
