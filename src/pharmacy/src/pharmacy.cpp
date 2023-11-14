// pharmacy.cpp
#include "pharmacy.h"
#include <stdexcept>
#include <algorithm>




namespace Pharmacy {
double add(double a, double b) {
  return a + b;
}

double subtract(double a, double b) {
  return a - b;
}

double multiply(double a, double b) {
  return a * b;
}

double divide(double a, double b) {
  if (b == 0) {
    throw std::invalid_argument("Division by zero");
  }

  return a / b;
}
}

Medication::Medication(const std::string &n, const std::string &c) : name(n), category(c) {}

void PharmacyMenu::displayMenu() {
  int choice;

  do {
    std::cout << "Pharmacy and Medication Management\n";
    std::cout << "---------------------------------------\n";
    std::cout << "1. Medication Management\n";
    std::cout << "2. Prescription Verification\n";
    std::cout << "3. Stock and Supplier Notifications\n";
    std::cout << "4. Reporting\n";
    std::cout << "5. Integrations\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        medicationManagement();
        break;

      case 2:
        prescriptionVerification();
        break;

      case 3:
        stockAndSupplierNotifications();
        break;

      case 4:
        reporting();
        break;

      case 5:
        integrations();
        break;

      case 0:
        std::cout << "Exiting the program. Goodbye!\n";
        break;

      default:
        std::cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 0);
}

void PharmacyMenu::medicationManagement() {
  int choice;

  do {
    std::cout << "Medication Management\n";
    std::cout << "-------------------------------\n";
    std::cout << "1. Add Medication\n";
    std::cout << "2. Update Medication\n";
    std::cout << "3. Delete Medication\n";
    std::cout << "4. Categorize Medication\n";
    std::cout << "5. Check Interactions\n";
    std::cout << "6. Check Side Effects\n";
    std::cout << "0. Back to Main Menu\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        addMedication();
        break;

      case 2:
        updateMedication();
        break;

      case 3:
        deleteMedication();
        break;

      case 4:
        categorizeMedication();
        break;

      case 5:
        checkInteractions();
        break;

      case 6:
        checkSideEffects();
        break;

      case 0:
        std::cout << "Returning to the main menu.\n";
        break;

      default:
        std::cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 0);
}

void PharmacyMenu::addMedication() {
  std::string name, category;
  std::cout << "Enter the name of the medication: ";
  std::cin >> name;
  std::cout << "Enter the category of the medication: ";
  std::cin >> category;
  medications.push_back(Medication(name, category));
  std::cout << "Medication added successfully.\n";
}

void PharmacyMenu::updateMedication() {
  std::string name;
  std::cout << "Enter the name of the medication to update: ";
  std::cin >> name;
  bool found = false;

  for (auto &med : medications) {
    if (med.name == name) {
      std::cout << "Enter the new category for the medication: ";
      std::cin >> med.category;
      std::cout << "Medication updated successfully.\n";
      found = true;
      break;
    }
  }

  if (!found) {
    std::cout << "Medication not found.\n";
  }
}

void PharmacyMenu::deleteMedication() {
  std::string name;
  std::cout << "Enter the name of the medication to delete: ";
  std::cin >> name;
  auto it = std::remove_if(medications.begin(), medications.end(),
  [name](const Medication& med) {
    return med.name == name;
  });

  if (it != medications.end()) {
    medications.erase(it, medications.end());
    std::cout << "Medication deleted successfully.\n";
  } else {
    std::cout << "Medication not found.\n";
  }
}

void PharmacyMenu::categorizeMedication() {
  std::string name;
  std::cout << "Enter the name of the medication to categorize: ";
  std::cin >> name;
  bool found = false;

  for (auto &med : medications) {
    if (med.name == name) {
      std::cout << "Enter the new category for the medication: ";
      std::cin >> med.category;
      std::cout << "Medication categorized successfully.\n";
      found = true;
      break;
    }
  }

  if (!found) {
    std::cout << "Medication not found.\n";
  }
}

void PharmacyMenu::checkInteractions() {
  std::string name;
  std::cout << "Enter the name of the medication to check interactions: ";
  std::cin >> name;
  bool found = false;

  for (const auto &med : medications) {
    if (med.name == name) {
      std::cout << "Interactions for " << med.name << ":\n";

      for (const auto &interaction : med.interactions) {
        std::cout << interaction << "\n";
      }

      found = true;
      break;
    }
  }

  if (!found) {
    std::cout << "Medication not found.\n";
  }
}

void PharmacyMenu::checkSideEffects() {
  std::string name;
  std::cout << "Enter the name of the medication to check side effects: ";
  std::cin >> name;
  bool found = false;

  for (const auto &med : medications) {
    if (med.name == name) {
      std::cout << "Side Effects for " << med.name << ":\n";

      for (const auto &sideEffect : med.sideEffects) {
        std::cout << sideEffect << "\n";
      }

      found = true;
      break;
    }
  }

  if (!found) {
    std::cout << "Medication not found.\n";
  }
}

void PharmacyMenu::prescriptionVerification() {
  int choice;

  do {
    std::cout << "Prescription Verification\n";
    std::cout << "---------------------------------\n";
    std::cout << "1. Sales Transactions\n";
    std::cout << "2. Drug Interactions Alerts\n";
    std::cout << "0. Back to Main Menu\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        salesTransactions();
        break;

      case 2:
        drugInteractionsAlerts();
        break;

      case 0:
        std::cout << "Returning to the main menu.\n";
        break;

      default:
        std::cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 0);
}

void PharmacyMenu::salesTransactions() {
  std::cout << "Sales Transactions selected.\n";
  // Satýþ iþlemleri için gerekli kodlarý burada ekleyebilirsiniz.
}

void PharmacyMenu::drugInteractionsAlerts() {
  std::cout << "Drug Interactions Alerts selected.\n";
  // Ýlaç etkileþimi uyarýlarý için gerekli kodlarý burada ekleyebilirsiniz.
}

void PharmacyMenu::stockAndSupplierNotifications() {
  int choice;

  do {
    std::cout << "Stock and Supplier Notifications\n";
    std::cout << "------------------------------------\n";
    std::cout << "1. Reorder Reminders\n";
    std::cout << "2. Expired Medication Tracking\n";
    std::cout << "0. Back to Main Menu\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        reorderReminders();
        break;

      case 2:
        expiredMedicationTracking();
        break;

      case 0:
        std::cout << "Returning to the main menu.\n";
        break;

      default:
        std::cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 0);
}

void PharmacyMenu::reorderReminders() {
  std::cout << "Reorder Reminders selected.\n";
  // Yeniden sipariþ hatýrlatmalarý için gerekli kodlarý burada ekleyebilirsiniz.
}

void PharmacyMenu::expiredMedicationTracking() {
  std::cout << "Expired Medication Tracking selected.\n";
  // Süresi dolmuþ ilaç takibi için gerekli kodlarý burada ekleyebilirsiniz.
}

void PharmacyMenu::reporting() {
  int choice;

  do {
    std::cout << "Reporting\n";
    std::cout << "-----------------------------\n";
    std::cout << "1. Popular Medications\n";
    std::cout << "2. Seasonal Sales\n";
    std::cout << "3. Customer Feedback\n";
    std::cout << "0. Back to Main Menu\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        popularMedications();
        break;

      case 2:
        seasonalSales();
        break;

      case 3:
        customerFeedback();
        break;

      case 0:
        std::cout << "Returning to the main menu.\n";
        break;

      default:
        std::cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 0);
}

void PharmacyMenu::popularMedications() {
  std::cout << "Popular Medications selected.\n";
  // Popüler ilaçlar için gerekli kodlarý burada ekleyebilirsiniz.
}

void PharmacyMenu::seasonalSales() {
  std::cout << "Seasonal Sales selected.\n";
  // Mevsimsel satýþlar için gerekli kodlarý burada ekleyebilirsiniz.
}

void PharmacyMenu::customerFeedback() {
  std::cout << "Customer Feedback selected.\n";
  // Müþteri geri bildirimleri için gerekli kodlarý burada ekleyebilirsiniz.
}

void PharmacyMenu::integrations() {
  int choice;

  do {
    std::cout << "Integrations\n";
    std::cout << "-----------------------------\n";
    std::cout << "1. Health Insurance Platforms\n";
    std::cout << "2. Patient Medical Record Systems\n";
    std::cout << "0. Back to Main Menu\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        healthInsurancePlatforms();
        break;

      case 2:
        patientMedicalRecordSystems();
        break;

      case 0:
        std::cout << "Returning to the main menu.\n";
        break;

      default:
        std::cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 0);
}

void PharmacyMenu::healthInsurancePlatforms() {
  std::cout << "Health Insurance Platforms selected.\n";
  // Saðlýk sigortasý platformlarýyla entegrasyon için gerekli kodlarý burada ekleyebilirsiniz.
}

void PharmacyMenu::patientMedicalRecordSystems() {
  std::cout << "Patient Medical Record Systems selected.\n";
  // Hasta týbbi kayýt sistemleriyle entegrasyon için gerekli kodlarý burada ekleyebilirsiniz.
}
