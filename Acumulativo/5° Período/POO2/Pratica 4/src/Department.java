import java.util.*;
class Department extends Party {
    private Vector staff = new Vector();

    public Department(String name) {
        super(name);
    }
    @Override
    public int getAnnualCost() {
        int result = 0;
        Iterator i = staff.iterator();
        while (i.hasNext()) {
            Employee each = (Employee) i.next();
            result += each.getAnnualCost();
        }
        return result;
    }
    @Override
    public int getHeadCount() {
        return staff.size();
    }
    public Enumeration getStaff() {
        return staff.elements();
    }
    public void addStaff(Employee arg) {
        staff.addElement(arg);
    }
}