 #ifndef DELEGATE_H
 #define DELEGATE_H

 #include <QItemDelegate>
 #include <QModelIndex>
 #include <QObject>
 #include <QSize>
 #include <QComboBox>

 class ComboDelegate : public QItemDelegate
 {
     Q_OBJECT

 public:
     ComboDelegate(QObject *parent = 0);

     QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const;

     void setEditorData(QWidget *editor, const QModelIndex &index) const;
     void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

 //    void updateEditorGeometry(QWidget *editor,
 //        const QStyleOptionViewItem &option, const QModelIndex &index) const;
		 
	 private slots:
		void emitCommitData();
 };

 #endif