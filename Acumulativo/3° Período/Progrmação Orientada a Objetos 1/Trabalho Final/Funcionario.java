import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Funcionario extends Pessoa {
    protected int numeroCarteira;
    protected String rg;
    protected String sexo;
    protected String cargo;
    protected double salario;
    private LocalDate dataIngresso;

    public Funcionario(String cpf, String nome, String endereco, String estadoCivil, LocalDate dataNascimento,
                       int numeroCarteira, String rg, String sexo, String cargo, double salario, LocalDate dataIngresso) {
        super(cpf, nome, endereco, estadoCivil, dataNascimento);
        this.numeroCarteira = numeroCarteira;
        this.rg = rg;
        this.sexo = sexo;
        this.cargo = cargo;
        if(dataIngresso == null)
            throw new DataNulaExecption("Data não pode ser nula");
        this.dataIngresso = dataIngresso;
        this.salario = salario;
    }

    public Funcionario() {
        super();
    }
    public int getNumeroCarteira() { return numeroCarteira; }
    public String getRg() { return rg; }
    public String getSexo() { return sexo; }
    public String getCargo() { return cargo; }
    public double getSalario() { return salario; }
    public String getDataIngresso() { return dataIngresso.format(DateTimeFormatter.ofPattern("dd/MM/yyyy")); }
    public int getDiaIngresso() { return dataIngresso.getDayOfMonth(); }
    public int getMesIngresso() { return dataIngresso.getMonthValue(); }
    public int getAnoIngresso() { return dataIngresso.getYear(); }

    public void setRg(String rg) { this.rg = rg; }
    public void setNumeroCarteira(int numeroCarteira) { this.numeroCarteira = numeroCarteira; }
    public void setDataIngresso(LocalDate dataIngresso) { this.dataIngresso = dataIngresso; }
    public void setSexo(String sexo) { this.sexo = sexo; }
    public void setCargo(String cargo) { this.cargo = cargo; }

    public void calcularSalario(double salario) {
        LocalDate compareDate = dataIngresso.plusYears(15);
        if (LocalDate.now().isAfter(compareDate))
            this.salario = salario * 1.1;
        else
            this.salario = salario;
    }
    public void imprimeDados(){
        System.out.println("Numero da carteira: " + numeroCarteira);
        System.out.println("RG: " + rg);
        System.out.println("Sexo: " + sexo);
        System.out.println("Cargo: " + cargo);
        System.out.println("Salario: " + salario);
        System.out.println("Data de ingresso: " + getDataIngresso());
    }
}
