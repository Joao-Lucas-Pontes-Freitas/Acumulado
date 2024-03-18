public abstract class JobItem {
    protected int quantity;
    public JobItem(int quantity) {
        this.quantity = quantity;
    }

    public int getTotalPrice() {
        return quantity * getUnitPrice();
    }

    public int getQuantity() {
        return quantity;
    }

    public abstract int getUnitPrice();
}
