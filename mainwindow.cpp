#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "book.h"

#include <QInputDialog>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    
    connect(ui->listWidget, &QListWidget::currentRowChanged,
            ui->stackedWidget, &QStackedWidget::setCurrentIndex);

    
    connect(ui->btnAddBook, &QPushButton::clicked,
            this, &MainWindow::onAddBookClicked);


    ui->tableResources->setColumnCount(4);
    ui->tableResources->setHorizontalHeaderLabels({"Title", "Author", "Year", "Available"});
    ui->tableResources->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    
    updateResourceTable();

    connect(ui->btnAddUser, &QPushButton::clicked, this, &MainWindow::onAddUserClicked);
    connect(ui->btnBorrow, &QPushButton::clicked, this, &MainWindow::onBorrowClicked);
    connect(ui->btnReturn, &QPushButton::clicked, this, &MainWindow::onReturnClicked);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onAddBookClicked() {
    QString title = QInputDialog::getText(this, "Add Book", "Enter Title:");
    if (title.isEmpty()) return;

    QString author = QInputDialog::getText(this, "Add Book", "Enter Author:");
    if (author.isEmpty()) return;

    QString isbn = QInputDialog::getText(this, "Add Book", "Enter ISBN:");
    if (isbn.isEmpty()) return;

    int year = QInputDialog::getInt(this, "Add Book", "Enter Year:", 2024);

    Book* b = new Book(title, author, year, isbn);
    library.addResource(b);

    QMessageBox::information(this, "Success", "Book added successfully!");
    updateResourceTable();
}

void MainWindow::updateResourceTable() {
    std::vector<Resource*> list = library.getAllResources();

    ui->tableResources->clearContents(); 
    ui->tableResources->setRowCount(static_cast<int>(list.size()));
    ui->tableResources->setColumnCount(4); 

    ui->tableResources->setHorizontalHeaderLabels({"Title", "Author", "Year", "Available"});

    for (int i = 0; i < static_cast<int>(list.size()); ++i) {
        Resource* r = list[i];

        ui->tableResources->setItem(i, 0, new QTableWidgetItem(r->getTitle()));
        ui->tableResources->setItem(i, 1, new QTableWidgetItem(r->getAuthor()));
        ui->tableResources->setItem(i, 2, new QTableWidgetItem(QString::number(r->getYear())));
        ui->tableResources->setItem(i, 3, new QTableWidgetItem(r->isAvailable() ? "Yes" : "No"));
    }
}
void MainWindow::onAddUserClicked() {
    QString id = QInputDialog::getText(this, "Add User", "Enter ID:");
    if (id.isEmpty()) return;

    QString name = QInputDialog::getText(this, "Add User", "Enter Name:");
    if (name.isEmpty()) return;

    QStringList roles = {"Student", "Faculty"};
    QString role = QInputDialog::getItem(this, "Add User", "Select Role:", roles, 0, false);
    if (role.isEmpty()) return;

    User* user;
    if (role == "Student") {
        QString major = QInputDialog::getText(this, "Student", "Enter Major:");
        user = new Student(id, name, major);
    } else {
        QString department = QInputDialog::getText(this, "Faculty", "Enter Department:");
        user = new Faculty(id, name, department);
    }

    library.addUser(user);
    QMessageBox::information(this, "Success", "User added successfully!");
    updateUsersTable();
}

void MainWindow::updateUsersTable() {
    std::vector<User*> users = library.getAllUsers();
    ui->tableUsers->setRowCount(static_cast<int>(users.size()));

    for (int i = 0; i < static_cast<int>(users.size()); ++i) {
        User* u = users[i];
        ui->tableUsers->setItem(i, 0, new QTableWidgetItem(u->getID()));
        ui->tableUsers->setItem(i, 1, new QTableWidgetItem(u->getName()));
        ui->tableUsers->setItem(i, 2, new QTableWidgetItem(u->getRole()));
    }
}

void MainWindow::onBorrowClicked() {
    QString userID = QInputDialog::getText(this, "Borrow", "Enter User ID:");
    QString title = QInputDialog::getText(this, "Borrow", "Enter Resource Title:");

    library.borrowResource(userID, title);
    updateResourceTable();
    updateLoansTable();
}

void MainWindow::onReturnClicked() {
    QString userID = QInputDialog::getText(this, "Return", "Enter User ID:");
    QString title = QInputDialog::getText(this, "Return", "Enter Resource Title:");

    library.returnResource(userID, title);
    updateResourceTable();
    updateLoansTable();
}

void MainWindow::updateLoansTable() {
    std::vector<Loan*> loans = library.getAllLoans();
    ui->tableLoans->setRowCount(static_cast<int>(loans.size()));

    for (int i = 0; i < static_cast<int>(loans.size()); ++i) {
        Loan* l = loans[i];
        ui->tableLoans->setItem(i, 0, new QTableWidgetItem(l->getUser()->getID()));
        ui->tableLoans->setItem(i, 1, new QTableWidgetItem(l->getResource()->getTitle()));
        ui->tableLoans->setItem(i, 2, new QTableWidgetItem(l->getLoanDate().toString()));
        ui->tableLoans->setItem(i, 3, new QTableWidgetItem(l->getDueDate().toString()));
    }
}
void MainWindow::onAddUserClicked() {
    QString id = QInputDialog::getText(this, "Add User", "Enter ID:");
    if (id.isEmpty()) return;

    QString name = QInputDialog::getText(this, "Add User", "Enter Name:");
    if (name.isEmpty()) return;

    QStringList roles = {"Student", "Faculty"};
    QString role = QInputDialog::getItem(this, "Add User", "Select Role:", roles, 0, false);
    if (role.isEmpty()) return;

    User* user;
    if (role == "Student") {
        QString major = QInputDialog::getText(this, "Student", "Enter Major:");
        user = new Student(id, name, major);
    } else {
        QString department = QInputDialog::getText(this, "Faculty", "Enter Department:");
        user = new Faculty(id, name, department);
    }

    library.addUser(user);
    QMessageBox::information(this, "Success", "User added successfully!");
    updateUsersTable();
}

void MainWindow::updateUsersTable() {
    std::vector<User*> users = library.getAllUsers();
    ui->tableUsers->setRowCount(static_cast<int>(users.size()));

    for (int i = 0; i < static_cast<int>(users.size()); ++i) {
        User* u = users[i];
        ui->tableUsers->setItem(i, 0, new QTableWidgetItem(u->getID()));
        ui->tableUsers->setItem(i, 1, new QTableWidgetItem(u->getName()));
        ui->tableUsers->setItem(i, 2, new QTableWidgetItem(u->getRole()));
    }
}

void MainWindow::onBorrowClicked() {
    QString userID = QInputDialog::getText(this, "Borrow", "Enter User ID:");
    QString title = QInputDialog::getText(this, "Borrow", "Enter Resource Title:");

    library.borrowResource(userID, title);
    updateResourceTable();
    updateLoansTable();
}

void MainWindow::onReturnClicked() {
    QString userID = QInputDialog::getText(this, "Return", "Enter User ID:");
    QString title = QInputDialog::getText(this, "Return", "Enter Resource Title:");

    library.returnResource(userID, title);
    updateResourceTable();
    updateLoansTable();
}

void MainWindow::updateLoansTable() {
    std::vector<Loan*> loans = library.getAllLoans();
    ui->tableLoans->setRowCount(static_cast<int>(loans.size()));

    for (int i = 0; i < static_cast<int>(loans.size()); ++i) {
        Loan* l = loans[i];
        ui->tableLoans->setItem(i, 0, new QTableWidgetItem(l->getUser()->getID()));
        ui->tableLoans->setItem(i, 1, new QTableWidgetItem(l->getResource()->getTitle()));
        ui->tableLoans->setItem(i, 2, new QTableWidgetItem(l->getLoanDate().toString()));
        ui->tableLoans->setItem(i, 3, new QTableWidgetItem(l->getDueDate().toString()));
    }
}

