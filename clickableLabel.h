#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H
#include <QLabel>
#include <QObject>
/**
 * @brief When the icon or image is clicked, this class will do the following action
 */
class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    /**
     * @brief Explicit constructor
     * @param parent
     */
    explicit ClickableLabel(QWidget* parent = nullptr);
    ~ClickableLabel();

signals:
    /**
     * @brief clicked action signal
     */
    void clicked();

protected:
    /**
     * @brief Even when pressed
     * @param event
     */
    void mousePressEvent(QMouseEvent* event);
};
#endif // CLICKABLELABEL_H
