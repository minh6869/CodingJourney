/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package bai5;

/**
 *
 * @author Bugs
 */
class SoNguyen {
    public int a;
    public int b;
    
    
   public SoNguyen(int a, int b){
       this.a = a;
       this.b = b;
   }
   
   public int tim_uoc_chung_max(int a, int b){
       if(b == 0)
           return a;
       if(a % b == 0)
           return b;
       return tim_uoc_chung_max(b, a%b);
   }
   
   public int tim_boi_chung_min(int tich, int uoc_chung_min){
       return tich/uoc_chung_min;
   }
  
}

    
