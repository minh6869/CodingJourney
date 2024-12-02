/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Main;
import java.util.*;
import java.io.*;
import bai3.*;
import bai4.*;
import bai5.*;
import bai6.*;
import bai7.*;
/**
 *
 * @author Bugs
 */
public class Main {
    public static void main(String args[]){
//        bai3 sv = new bai3();
//        sv.nhap_thong_tin();
//        final int i = 10;
       
        bai6 so_nguyen = new bai6();
        Scanner x = new Scanner(System.in);
        System.out.println("Nhap so nguyen a: ");
        int a = x.nextInt();    
        so_nguyen.xuat_so_nguyen_to(a);
        x.close();
//          bai7 a = new bai7();
//          a.xuat(3);
//        x.close();
    }
}
