class LaborItem extends JobItem {
    private Employee employee;

    public LaborItem(int quantity, Employee employee) {
        super(quantity);
        this.employee = employee;
    }


    public int getUnitPrice() {
        return employee.getRate();
    }
    public Employee getEmployee() {
        return employee;
    }
}