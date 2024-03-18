import java.io.Serializable;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Transacao implements Serializable {
    private LocalDate data;
    private double valor;
    private String canal;
    public Transacao(LocalDate data, double valor, String canal) {
        this.data = data;
        this.valor = valor;
        this.canal = canal;
    }
    public String getData() {
        return data.format(DateTimeFormatter.ofPattern("dd/MM/yyyy"));
    }
    public void setData(LocalDate data) {
        this.data = data;
    }
    public double getValor() {
        return valor;
    }
    public void setValor(double valor) {
        this.valor = valor;
    }
    public String getCanal() {
        return canal;
    }
    public void setCanal(String canal) {
        this.canal = canal;
    }
    public void imprimeTransacao(){
        System.out.println("Data: " + this.getData() + " Valor: " + this.getValor() + " Canal: " + this.getCanal());
    }
}

