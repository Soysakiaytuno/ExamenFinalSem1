#include <iostream>
#include <map>
#include <string>
using namespace std;

bool es_digito(char c);
bool formato_de_fecha(string fecha);
void funcion_add(map<string,string>& base_de_datos,string fecha,string evento);
void funcion_delete(map<string,string>& base_de_datos, string fecha);
void funcion_find(map<string,string>base_de_datos, string fecha);
void funcion_print(const map<string,string>& base_de_datos);
map<string, string> reverse_map(map<string, string> m);
void funcion_delete_one(map<string,string>& base_de_datos, string evento);
string formatear_fecha(string fecha);

int main (){
   string comando;
   map<string,string>base_de_datos;
   string fecha;
   string evento;

///"Funcion" para determinar el tipo de comando que quiere el usuario///

while(true){
    cin>>comando;
    if (comando == "Stop" ){
        break;
    }
    else if (comando == "Add" ){
        cin >> fecha >> evento;
         if (formato_de_fecha(fecha)) {
                funcion_add(base_de_datos, fecha, evento);
            } else {
                cout << "Wrong date format: " << fecha << endl;
            }
    }
    else if (comando == "Del") {
            cin >> fecha;
            if (formato_de_fecha(fecha)) {
                char siguiente_char = cin.peek(); // Miramos el siguiente carácter sin extraerlo
                if (siguiente_char == '\n' || siguiente_char == EOF) { // Si es el final de la línea o archivo
                    funcion_delete(base_de_datos, fecha); 
                } else {
                    getline(cin, evento); 
                    if (!evento.empty()) {
                        evento.erase(0, 1); // Eliminamos el espacio en blanco al inicio del evento
                    }
                    funcion_delete_one(base_de_datos, evento); 
                }
    }
    }
    else if(comando == "Find"){
        cin >> fecha;
        if (formato_de_fecha(fecha)) {
        funcion_find(base_de_datos, fecha);
        }
    }
    else if(comando == "Print"){
        funcion_print(base_de_datos);
    }
    else {
        cout<<"Unkown command: "<< comando <<endl;
    }

}
return 0;
}
    bool es_digito(char c){
        return c >= '0' && c <= '9'; //Ver si son numeros
    }
    bool formato_de_fecha(string fecha){
    // Encontrar las posiciones de los separadores 
    int posicion1 = 0;
    int posicion2 = 0;
    for (int i = 0; i < fecha.size(); ++i) {
        if (fecha[i] == '-') {
            if (posicion1 == 0) {
                posicion1 = i;
            } else {
                posicion2 = i;
                break;
            }
        }
    }

    // Verificar si hay dos separadores minimo
    if (posicion1 == 0 || posicion2 == 0) {
        return false;
    }

    // Separar el string en varias partes
    int year = 0;
    bool es_year_negativo = false;
    for (int i = 0; i < posicion1; ++i) {
        if (i == 0 && fecha[i] == '-') {
            es_year_negativo = true;
            continue;
        }
        if (i == 0 && fecha[i] == '+') {
            es_year_negativo = false;
            continue;
        }
        if (!es_digito(fecha[i])) {
            return false;  // No es un dígito
        }
        year = year * 10 + (fecha[i] - '0');
    }
    
   
    int month = 0;
    bool es_month_negativo = false;
    for (int i = posicion1 + 1; i < posicion2; ++i) {
        if (i == posicion1 + 1 && fecha[i] == '-') {
            es_month_negativo = true;
            continue;
        }
        //
        if (i == posicion1 + 1 && fecha[i] == '+') {
            es_month_negativo = false;
            continue;
        }
        //
        if (!es_digito(fecha[i])) {
            return false;  // No es un dígito
        }
        month = month * 10 + (fecha[i] - '0');
    }

    int day = 0;
    bool es_day_negativo = false;
    for (int i = posicion2 + 1; i < fecha.size(); ++i) {
        if (i == posicion2 + 1 && fecha[i] == '-') {
            es_day_negativo = true;
            continue;
        }
        if (i == posicion2 + 1 && fecha[i] == '+') {
            es_day_negativo = false;
            continue;
        }
        if (!es_digito(fecha[i])) {
            return false;  // No es un dígito
        }
        day = day * 10 + (fecha[i] - '0');
    }
    // Verificar el rango del mes y el día
    if (month < 1 || month > 12) {
        cout << "Month value is invalid: " << month << endl;
        return false;
    }
    if (day < 1 || day > 31) {
        cout << "Day value is invalid: " << day << endl;
        return false;
    }
    return true;
    }
void funcion_add(map<string, string>& base_de_datos, string fecha, string evento) {
    if (base_de_datos.find(evento) == base_de_datos.end()){
    base_de_datos[evento] = fecha;
    }
}
void funcion_delete(map<string,string>& base_de_datos, string fecha){
    int contador = 0;
    for (auto it = base_de_datos.begin(); it != base_de_datos.end();) {
        if (it->second < fecha) { 
            it = base_de_datos.erase(it);
            ++contador;
        } else {
            ++it;
        }
    }
    cout << "Deleted " << contador << " events" << endl;
}

void funcion_delete_one(map<string,string>& base_de_datos, string evento){
    auto it = base_de_datos.find(evento);
    if(it != base_de_datos.end()){
        base_de_datos.erase(it);
        cout << "Deleted successfully!" << endl;
    } else {
        cout << "Event not found" << endl;
    }
}

void funcion_find(map<string,string>base_de_datos, string fecha){
        reverse_map(base_de_datos);
        for(const auto& item : base_de_datos) {
        if(item.second == fecha){
        cout << item.first << endl;
        }
        }
    }
void funcion_print(const map<string,string>& base_de_datos){
    for(const auto& item : base_de_datos) {
        string fecha = formatear_fecha(item.second);
        // Verificar si el primer carácter del año es un dígito positivo
        if (fecha[0] != '-') {
        string fecha_formateada = formatear_fecha(item.second);
        cout << fecha_formateada << " " << item.first << endl;
    }
}
}
map<string, string> reverse_map(map<string, string> m) {
    map<string, string> result;
    for(const auto& item : m) {
        result[item.second] = item.first;
    }
    return result;
}
string formatear_fecha(string fecha) {
    string year, month, day;
    int guion1 = -1, guion2 = -1;
    bool es_year_negativo = false;

    // Encuentra la posición de los guiones
    for (int i = 0; i < fecha.length(); ++i) {
        if (fecha[i] == '-') {
            if (guion1 == -1) {
                guion1 = i;
                if (i == 0) {
                    es_year_negativo = true;
                    continue;
                }
            } else {
                guion2 = i;
                break;
            }
        }
    }

    // Extrae año, mes y día
    year = fecha.substr((es_year_negativo ? 1 : 0), guion1 - (es_year_negativo ? 1 : 0));
    month = fecha.substr(guion1 + 1, guion2 - guion1 - 1);
    day = fecha.substr(guion2 + 1);

    // Añade ceros si es necesario
    if (!es_year_negativo && year.length() < 4) {
        year.insert(0, 4 - year.length(), '0');
    }
    if (month.length() < 2) {
        month.insert(0, 2 - month.length(), '0');
    }
    if (day.length() < 2) {
        day.insert(0, 2 - day.length(), '0');
    }

    // Combina las partes en la fecha final
    return (es_year_negativo ? "-" : "") + year + "-" + month + "-" + day;
}