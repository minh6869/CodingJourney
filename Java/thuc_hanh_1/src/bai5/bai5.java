/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package bai5;

/**
 *
 * @author Bugs
 */
public class bai5 {
    public void xuat_uocchung_boichung(int a, int b){
        SoNguyen x = new SoNguyen(a, b);
        int uoc_chung_max = x.tim_uoc_chung_max(x.a, x.b);
        int boi_chung_min = x.tim_boi_chung_min(x.a * x.b, uoc_chung_max);
        System.out.println("uoc chung lon nhat hai so " + x.a + " va " + x.b + " la " + uoc_chung_max);
        System.out.println("boi chung lon nhat hai so " + x.a + " va " + x.b + " la " + boi_chung_min);
        
    }
}
