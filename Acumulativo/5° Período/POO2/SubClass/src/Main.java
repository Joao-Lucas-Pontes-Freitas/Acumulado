public class Main{
    public static void main(String[] args) {
        Employee kent = new Employee(50);
        JobItem j1 = new LaborItem(5, 0, true, kent);
        JobItem j2 = new LaborItem(15, 10, false, null);
        int total = j1.getTotalPrice() + j2.getTotalPrice();
    }
}