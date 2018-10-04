#include <QtGui>

 #include "combodelegate.h"

 ComboDelegate::ComboDelegate(QObject *parent)
     : QItemDelegate(parent)
 {
 }

 QWidget *ComboDelegate::createEditor(QWidget *parent,
     const QStyleOptionViewItem &/* option */,
     const QModelIndex &/* index */) const
 {
     QComboBox *comboBox = new QComboBox(parent);
	 
	 comboBox->addItem("faves");
	 comboBox->addItem("bass");
	 comboBox->addItem("lead");
	 comboBox->addItem("pad");
	 comboBox->addItem("string");
	 comboBox->addItem("brass");
	 comboBox->addItem("key");
	 comboBox->addItem("comp");
	 comboBox->addItem("drum");
	 comboBox->addItem("sfx"); 
	 
	 connect(comboBox, SIGNAL(activated(int)), this, SLOT(emitCommitData()));

     return comboBox;
 }

 void ComboDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const
 {
     QComboBox *comboBox = qobject_cast<QComboBox *>(editor);
     if (!comboBox)
         return;

     int pos = comboBox->findText(index.model()->data(index).toString(),
                                  Qt::MatchExactly);
     comboBox->setCurrentIndex(pos);
 }


 void ComboDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
 {
     QComboBox *comboBox = qobject_cast<QComboBox *>(editor);
     if (!comboBox)
         return;

     model->setData(index, comboBox->currentText());
 }



// void ComboDelegate::updateEditorGeometry(QWidget *editor,
//     const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
// {
//     editor->setGeometry(option.rect);
// }

 
void ComboDelegate::emitCommitData()
 {
     emit commitData(qobject_cast<QWidget *>(sender()));
 }
