/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package bai7;
import bai6.*;
import java.util.*;

/**
 *
 * @author Bugs
 */
public class MangSoNguyen {
    public int[] arr ;
    public int n;
    public SoNguyenTo songuyento;
    
    
    public MangSoNguyen(int n){
        this.n = n;
        this.songuyento = new SoNguyenTo(n);
        arr = new int[n];
        Scanner x = new Scanner(System.in);
        for (int i = 0; i < n; i++) {
            System.out.println("Nhap phan tu thu " + i + ": ");
            arr[i] = x.nextInt();
        }
        x.close();
        
    }
    
    public void print(){
        System.out.println("Mang sau khi nhap la:" );
        for (int i = 0; i < this.n; i++) {
            System.out.println(" " + arr[i] );
        }
    }
    
    public int so_max(){
        int max = this.arr[0];
        for (int i = 0; i < this.n; i++) {
            max = Math.max(max, arr[i]);
        }
        return max;
    }
    
    
    
    
   
    
    
}
