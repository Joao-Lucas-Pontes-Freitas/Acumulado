public class PartsItem extends JobItem{
    private int unitPrice;
    public PartsItem(int quantity, int unitPrice){
        super(quantity);
        this.unitPrice = unitPrice;
    }
    public int getUnitPrice() {
        return unitPrice;
    }
}
