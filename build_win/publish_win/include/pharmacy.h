// pharmacy.h

#pragma once

namespace Pharmacy {
// Ýlgili sýnýflar, fonksiyonlar ve diðer deklarasyonlar burada yer alýr.
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
} // namespace Pharmacy

#ifndef PHARMACY_H
#define PHARMACY_H

#include <iostream>
#include <string>
#include <vector>


class Medication {
 public:
  std::string name;
  std::string category;
  std::vector<std::string> interactions;
  std::vector<std::string> sideEffects;

  Medication(const std::string &n, const std::string &c);
};

class PharmacyMenu {
 private:
  std::vector<Medication> medications;

 public:
  void displayMenu();
  void medicationManagement();
  void addMedication();
  void updateMedication();
  void deleteMedication();
  void categorizeMedication();
  void checkInteractions();
  void checkSideEffects();

  void prescriptionVerification();
  void salesTransactions();
  void drugInteractionsAlerts();

  void stockAndSupplierNotifications();
  void reorderReminders();
  void expiredMedicationTracking();

  void reporting();
  void popularMedications();
  void seasonalSales();
  void customerFeedback();

  void integrations();
  void healthInsurancePlatforms();
  void patientMedicalRecordSystems();
};

#endif // PHARMACY_H
