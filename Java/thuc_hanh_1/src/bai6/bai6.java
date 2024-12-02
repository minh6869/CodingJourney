/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package bai6;
import java.util.*;

/**
 *
 * @author Bugs
 */
public class bai6 {
    public void xuat_so_nguyen_to(int n){
        SoNguyenTo x = new SoNguyenTo(n);
        List<Integer> array_n = new ArrayList<>();
        for (int i = 0; i < x.n; i++) {
            array_n.add(i);
        }
        List<Integer> primes = x.tim_so_nguyen_to(array_n, x.n);
        System.out.printf("Cac so nguyen to nho hon %d la: ",n);
        for (int prime : primes) {
            System.out.format(" %d",prime);
        }
    }
    
    
}
