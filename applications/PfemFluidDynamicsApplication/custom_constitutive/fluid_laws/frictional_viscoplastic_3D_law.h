//-------------------------------------------------------------
//         ___  __           ___ _      _    _
//  KRATOS| _ \/ _|___ _ __ | __| |_  _(_)__| |
//        |  _/  _/ -_) '  \| _|| | || | / _` |
//        |_| |_| \___|_|_|_|_| |_|\_,_|_\__,_|DYNAMICS
//
//  BSD License:    PfemFluidDynamicsApplication/license.txt
//
//  Main authors:   Riccardo Rossi, Alessandro Franci
//  Collaborators:  Massimiliano Zecchetto
//
//-------------------------------------------------------------
//

#if !defined(KRATOS_FRICTIONAL_VISCOPLASTIC_LAW_3D_H_INCLUDED)
#define KRATOS_FRICTIONAL_VISCOPLASTIC_LAW_3D_H_INCLUDED

// System includes

// External includes

// Project includes
#include "fluid_constitutive_law.h"

namespace Kratos
{
    /**
 * Defines a 3D Frictional Viscoplastic non-Newtonian constitutive law
 * This material law is defined by the parameters:
 * 1) DYNAMIC_VISCOSITY
 * 2) YIELD_SHEAR
 * 3) ADAPTIVE_EXPONENT
 */
    class KRATOS_API(PFEM_FLUID_DYNAMICS_APPLICATION) FrictionalViscoplastic3DLaw : public PfemFluidConstitutiveLaw
    {
    public:
        /**
     * Type Definitions
     */
        typedef ProcessInfo ProcessInfoType;
        typedef ConstitutiveLaw BaseType;
        typedef std::size_t SizeType;

        /**
     * Counted pointer of FrictionalViscoplastic3DLaw
     */
        KRATOS_CLASS_POINTER_DEFINITION(FrictionalViscoplastic3DLaw);

        /**
     * Life Cycle
     */

        /**
     * Default constructor.
     */
        FrictionalViscoplastic3DLaw();

        /**
     * Clone function (has to be implemented by any derived class)
     * @return a pointer to a new instance of this constitutive law
     */
        ConstitutiveLaw::Pointer Clone() const override;

        /**
     * Copy constructor.
     */
        FrictionalViscoplastic3DLaw(const FrictionalViscoplastic3DLaw &rOther);

        /**
     * Destructor.
     */
        ~FrictionalViscoplastic3DLaw() override;

        /**
     * Operators
     */

        /**
     * Operations needed by the base class:
     */

        /**
     * @return Working space dimension constitutive law
     */
        SizeType WorkingSpaceDimension() override;

        /**
     * @return Size of the strain vector (in Voigt notation) for the constitutive law
     */
        SizeType GetStrainSize() const override;

        void CalculateMaterialResponseCauchy(Parameters &rValues) override;

        /**
     * This function is designed to be called once to perform all the checks needed
     * on the input provided. Checks can be "expensive" as the function is designed
     * to catch user's errors.
     * @param rMaterialProperties
     * @param rElementGeometry
     * @param rCurrentProcessInfo
     * @return
     */
        int Check(const Properties &rMaterialProperties, const GeometryType &rElementGeometry,
                  const ProcessInfo &rCurrentProcessInfo) const override;

        /**
     * Input and output
     */

        /**
     * Turn back information as a string.
     */
        std::string Info() const override;

    protected:
        ///@name Protected static Member Variables
        ///@{
        ///@}
        ///@name Protected member Variables
        ///@{
        ///@}
        ///@name Protected Operators
        ///@{
        ///@}
        ///@name Protected Operations
        ///@{

        /// Get the effective viscosity (in dynamic units -- Pa s) for the fluid.
        double GetEffectiveViscosity(ConstitutiveLaw::Parameters &rParameters) const override;

        /// Get the effective density for the fluid.
        double GetEffectiveDensity(ConstitutiveLaw::Parameters &rParameters) const override;

        /// Get the effective friction angle for the fluid.
        double GetEffectiveFrictionAngle(ConstitutiveLaw::Parameters &rParameters) const;

        /// Get the effective cohesion for the fluid.
        double GetEffectiveCohesion(ConstitutiveLaw::Parameters &rParameters) const;

        /// Get the effective dynamic viscosity for the fluid.
        double GetEffectiveDynamicViscosity(ConstitutiveLaw::Parameters &rParameters) const;

        ///@}

    private:
        ///@name Static Member Variables
        ///@{

        ///@}
        ///@name Member Variables
        ///@{

        ///@}
        ///@name Private Operators
        ///@{

        ///@}
        ///@name Private Operations
        ///@{
        ///@}

        ///@}
        ///@name Private  Access
        ///@{
        ///@}

        ///@}
        ///@name Serialization
        ///@{
        friend class Serializer;

        void save(Serializer &rSerializer) const override;

        void load(Serializer &rSerializer) override;
        ///@}

    }; // Class FrictionalViscoplastic3DLaw

} // namespace Kratos.

#endif // KRATOS__FRICTIONAL_VISCOPLASTIC_LAW_3D_H_INCLUDED  defined
