public abstract class Party {
    protected String name;

    public Party(String name) {
        this.name = name;
    }

    public abstract int getAnnualCost();

    public abstract int getHeadCount();

    public String getName() {
        return name;
    }
}
