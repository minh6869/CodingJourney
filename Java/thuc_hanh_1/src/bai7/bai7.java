/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package bai7;
import java.util.*;


/**
 *
 * @author Bugs
 */
public class bai7 {
    public void xuat(int n){
        MangSoNguyen mang = new MangSoNguyen(n);
        mang.print();
        int max = mang.so_max();
        List<Integer> list = new ArrayList<>();
        for (int i : mang.arr) {
            list.add(i);
        }
        list = mang.songuyento.tim_so_nguyen_to(list, max);
        System.out.println("Cac so nguyen co trong mang la: ");
        for(int prime : list){
            System.out.println(" " + prime);
        }
        
//        x.xuat_so_nguyen_to(max);
//        List<Integer> primes = a.primes(max);
        
    }
}
